// https://drewdevault.com/2016/04/12/How-to-write-a-better-bloom-filter-in-C.html
#ifndef _BLOOM_H
#define _BLOOM_H
#include <stddef.h>
#include <stdbool.h>

typedef unsigned int (*hash_function)(const void *data);
typedef struct bloom_filter * bloom_t;

/* Creates a new bloom filter with no hash functions and size * 8 bits. */
bloom_t bloom_create(size_t size);
/* Frees a bloom filter. */
void bloom_free(bloom_t filter);
/* Adds a hashing function to the bloom filter. You should add all of the
 * functions you intend to use before you add any items. */
void bloom_add_hash(bloom_t filter, hash_function func);
/* Adds an item to the bloom filter. */
void bloom_add(bloom_t filter, const void *item);
/* Tests if an item is in the bloom filter.
 *
 * Returns false if the item has definitely not been added before. Returns true
 * if the item was probably added before. */
bool bloom_test(bloom_t filter, const void *item);

#endif

struct bloom_hash {
    hash_function func;
    struct bloom_hash *next;
};

struct bloom_filter {
    struct bloom_hash *func;
    void *bits;
    size_t size;
};
bloom_t bloom_create(size_t size) {
	bloom_t res = calloc(1, sizeof(struct bloom_filter));
	res->size = size;
	res->bits = malloc(size);
	return res;
}

void bloom_free(bloom_t filter) {
	if (filter) {
		while (filter->func) {
			struct bloom_hash *h;
			filter->func = h->next;
			free(h);
		}
		free(filter->bits);
		free(filter);
	}
}

void bloom_add_hash(bloom_t filter, hash_function func) {
	struct bloom_hash *h = calloc(1, sizeof(struct bloom_hash));
	h->func = func;
	struct bloom_hash *last = filter->func;
	while (last && last->next) {
		last = last->next;
	}
	if (last) {
		last->next = h;
	} else {
		filter->func = h;
	}
}