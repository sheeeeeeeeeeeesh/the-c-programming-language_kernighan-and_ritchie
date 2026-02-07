// Функция не учитывает случай, когда компилятор позволяет писать следующим образом: c = '//';

void delete_comments() {
	char c, prevc;

	while ((c = getchar()) != EOF) {
		
		if (c == '"') {
			putchar(c);
			prevc = c;
			while ((c = getchar()) != '"' || prevc == '\\') {
				putchar(c);
				prevc = c;
				c = getchar();
			}
			putchar(c);
		}

		else if (c == '/') {
			prevc = c;
			c = getchar();

			if (c == '/') {
				while ((c = getchar()) != '\n');
				putchar(c);
			}
			else if (c == '*') {
				while (c != '/' || prevc != '*') 
				{
					prevc = c;
					c = getchar();
				}
			}
			else 
			{
				putchar(prevc);
				putchar(c);
			}
		}

		else putchar(c);
	}
}
