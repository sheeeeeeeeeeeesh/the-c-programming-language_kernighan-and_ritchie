// Не учитывается случай, когда двойные кавычки пишутся в комментариях
// Возвращает 1, если комментарий закончен на данной строке; 0 - когда комментарий не закончен на данной строке
int delete_comments(char line[], int comment_ended) {
	int ind = 0;

	if (comment_ended == 0) {
		comment_ended = delete_long_comment(line, ind);

		if (comment_ended == 1) return comment_ended;
	}

	while (line[ind] != '\n' || line[ind] != EOF) {
		if (line[ind] == '/' && (line[ind + 1] == '*' || line[ind + 1] == '/')) {

			if (!between_quote_marks(line, ind)) {

				if (line[ind + 1] == '/') line[ind] = NULL;

				else if (line[ind + 1] == '*') {
					comment_ended = delete_long_comment(line, ind);

					if (comment_ended == 1) return comment_ended;
				}
			}
		}
	}

	return 0;
}

int delete_long_comment(char line[], int ind) {
	while ((line[ind] != '*' || line[ind + 1] != '/') && line[ind] != '\n') {
		line[ind] = '\0';
		ind++;
	}

	if (line[ind] == '\n') return 1;

	line[ind] = '\0';
	return 0;
}

int between_quote_marks(char line[], int ind) {
	int inds[2], quote_marks_counter, marks_ind;

	marks_ind = 0;
	quote_marks_counter = 0;
	inds[0] = 0;
	inds[1] = 0;

	while (line[marks_ind] != '\n' || line[marks_ind] != EOF) {
		if (line[marks_ind] == '"') {
			inds[quote_marks_counter] = marks_ind;
			quote_marks_counter++;
			
			if (quote_marks_counter == 2) {
				if (inds[0] < ind && ind < inds[1]) return 1;
				else {
					inds[0] = 0;
					inds[1] = 0;
					quote_marks_counter = 0;
				}
			}
		}

		marks_ind++;
	}

	if (inds[0] < ind && ind < inds[1]) return 1;
	return 0;
}

int getline(char line[]) {
	char character;
	int i = 0;

	// Опущено условие: character != '\n'
	while ((character = getchar()) != EOF && i < MAX_LINE_LENGTH - 1) {
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
