#include <stdlib.h>
#include <string.h>
#include <sqlite3ext.h>

enum e_macro
{
	NEW,
	GET
};

struct sqlite3_api_routines	*new_sqlite3_api_routines(void)
{
	struct sqlite3_api_routines	*new;

	if (!(new = (struct sqlite3_api_routines*)malloc(sizeof(struct sqlite3_api_routines))))
		return (NULL);
	new->aggregate_context = NULL;
	new->aggregate_count = NULL;
	new->bind_blob = NULL;
	new->bind_double = NULL;
	new->bind_int = NULL;
	new->bind_int64 = NULL;
	new->bind_null = NULL;
	new->bind_parameter_count = NULL;
	new->bind_parameter_index = NULL;
	new->bind_parameter_name = NULL;
	new->bind_text = NULL;
	new->bind_text16 = NULL;
	new->bind_value = NULL;
	new->busy_handler = NULL;
	new->busy_timeout = NULL;
	new->changes = NULL;
	new->close = NULL;
	new->)) = NULL;
	new->)) = NULL;
	new->column_blob = NULL;
	new->column_bytes = NULL;
	new->column_bytes16 = NULL;
	new->column_count = NULL;
	new->column_database_name = NULL;
	new->column_database_name16 = NULL;
	new->column_decltype = NULL;
	new->column_decltype16 = NULL;
	new->column_double = NULL;
	new->column_int = NULL;
	new->column_int64 = NULL;
	new->column_name = NULL;
	new->column_name16 = NULL;
	new->column_origin_name = NULL;
	new->column_origin_name16 = NULL;
	new->column_table_name = NULL;
	new->column_table_name16 = NULL;
	new->column_text = NULL;
	new->column_text16 = NULL;
	new->column_type = NULL;
	new->column_value = NULL;
	new->commit_hook = NULL;
	new->complete = NULL;
	new->complete16 = NULL;
