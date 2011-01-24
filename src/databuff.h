#include <stddef.h>

struct data_buffer {
	size_t size;
	size_t index;
	unsigned char * buffer;
};

/* Allocate and initialize a new data_buffer */
struct data_buffer * data_buffer_new(size_t size);

/* Deallocate a data_buffer */
void data_buffer_delete(struct data_buffer *db);

/* Push data into the buffer */
int data_buffer_push(struct data_buffer *db, unsigned char data);

/* Push data out of the buffer */
int data_buffer_pop(struct data_buffer *db, unsigned char *data);

