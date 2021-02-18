CC = gcc 

csv: csv.c functions/row_count.c functions/column_count.c functions/semi_group_operation.c
	$(CC) csv.c functions/row_count.c functions/column_count.c functions/semi_group_operation.c -o csv

clean: 
	rm csv 
