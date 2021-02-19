CC = gcc 

csv: csv.c functions/get_dimensions.c functions/record.c functions/semi_group_operation.c
	$(CC) csv.c functions/record.c functions/get_dimensions.c functions/semi_group_operation.c -o csv

clean: 
	rm csv 
