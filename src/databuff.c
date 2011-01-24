#include <databuff.h>

/* Allocate and initialize a new data_buffer */
struct data_buffer * data_buffer_new(size_t size)
{
	struct data_buffer * db;

	/* Allocate a block of memory for a new data_buffer */
	db = malloc(sizeof(struct data_buffer));
	if (db == NULL) {
		return NULL;
	}

	/* Initialize the members of the new data_buffer */
	memset(db, 0, sizeof(struct data_buffer));
	db->size   = size;
	db->index  = 0;
	db->buffer = malloc(db->size);
	if (db->buffer == NULL) {
		free(db);
		return NULL;
	}

	/* Return the newly created data_buffer */
	return db;
}

/* Deallocate a data_buffer */
void data_buffer_delete(struct data_buffer *db)
{
	/* Check for a null pointer */
	if (db == NULL) {
		return;
	}

	/* Deallocate the buffer */
	if (db->buffer != NULL) {
	free(db->buffer);
	db->buffer = NULL;
	}

	/* Deallocate the Item object itself */
	free(db);
}

int data_buffer_push(struct data_buffer *db, unsigned char data)
{
	if (db->index > db->size) {
		void * temp;
		temp = realloc(db->buffer, db->size +1);
		if (temp == NULL) {
			return -1;
		}
		db->buffer = (unsigned char *) temp;
	}

	db->buffer[db->index] = data;
	db->index++;

	return 0;
}

int data_buffer_pop(struct data_buffer *db, unsigned char *data)
{
	if (db->index < 0) {
		return -1;
	}

	*data = db->buffer[db->index]:
	db->index--;

	return 0;
}


