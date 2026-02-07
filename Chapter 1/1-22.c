void shrink(char string[], char shrinked_string[]) {
	int ind1, ind2, str_length;
	str_length = array_length(string);

	for (ind1 = MAX_PART_LENGTH; ind1 < str_length; ind1 += MAX_PART_LENGTH) {

		if (string[ind1 - 1] == '\t' || string[ind1 - 1] == '_') {
			add(string, shrinked_string, ind1 - MAX_PART_LENGTH, ind1);
			ind2 = array_length(shrinked_string);
			while (string[ind1] == '_' || string[ind1] == '\t' && ind1 < MAX_LINE_LENGTH) {
				shrinked_string[ind2] == string[ind1];
				ind1++;
				ind2++;
			}
			shrinked_string[ind2] = '\n';
			shrinked_string[++ind2] = '\0';
		}

		else {
			ind2 = ind1;
			while (string[ind1 - 1] != '_' && string[ind1 - 1] != '\t' && ind2 - MAX_PART_LENGTH + 1 < ind1) 
				ind1--;

			if (string[ind1 - 1] == '_' || string[ind1 - 1] == '\t') {
				add(string, shrinked_string, ind2 -	MAX_PART_LENGTH, ind1);
				ind2 = array_length(shrinked_string);
				shrinked_string[ind2] = '\n';
				shrinked_string[++ind2] = '\0';
			}
			else {
				add(string, shrinked_string, ind2 - MAX_PART_LENGTH, ind2);
				shrinked_string[ind2] = '\n';
				shrinked_string[++ind2] = '\0';
				ind1 = ind2;
			}
		}
	}

	if (str_length % MAX_PART_LENGTH != 0) add(string, shrinked_string, ind1 - MAX_PART_LENGTH, str_length);
}

int getline(char line[]) {
	char character;
	int i = 0;

	while ((character = getchar()) != EOF && character != '\n' && i < MAX_LINE_LENGTH - 1) {
		line[i] = character;
		i++;
	}

	if (character == '\n') {
		line[i] = '\n';
		i++;
	}

	line[i] = '\0';
	return i;
}

/// Индексы from_ind, to_ind указывают из каких позиций массива from[] нужно добавлять элементы в конец массива to[]
void add(char from[], char to[], int from_ind, int to_ind) {
	if (to_ind > array_length(from)) {
		printf("Index out of bounds exception");
		return -1;
	}

	int ind = array_length(to);
	while (from_ind < to_ind) {
		to[ind] = from[from_ind];
		ind++;
		from_ind++;
	}
	to[ind] = '\0';
}

int array_length(char array[]) {
	int i = 0;
	while (array[i] != NULL) i++;
	return i;
}
