#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"

#define YANDERE_PNG_SOURCE_ID "<li><a class=\"original-file-unchanged\" id=\"png\" href=\""
#define YANDERE_JPG_SOURCE_ID "<li><a class=\"original-file-changed\" id=\"highres\" href=\""

/* Given a https://yande.re/ url,
 * parse the html to get the source image url
 */
char* yandere_get_image_url(char *web_url)
{
	/* Fetch the html source code of the website */
	char *html_content = get_html(web_url);

	/* Find the source image link */
	char *index = strstr(html_content, YANDERE_PNG_SOURCE_ID);
	char *img_src_url;

	/* If found, return it */
	if (index) {
		index = &index[strlen(YANDERE_PNG_SOURCE_ID)];
		char *walker = index;
		while (*walker != '"')
			walker = &walker[1];
		walker[0] = '\0';

		unsigned int url_len = strlen(index) + 1;
		img_src_url = malloc(sizeof(char) * url_len);
		img_src_url[0] = '\0';
		strcat(img_src_url, index);
	}
	else if (strstr(html_content, YANDERE_JPG_SOURCE_ID)) {
		index = strstr(html_content, YANDERE_JPG_SOURCE_ID);
		char *walker = index;
		while (*walker != '"')
			walker = &walker[1];
		walker[0] = '\0';

		unsigned int url_len = strlen(index) + 1;
		img_src_url = malloc(sizeof(char) * url_len);
		img_src_url[0] = '\0';
		strcat(img_src_url, index);
	}
	else {
		printf("Error: yandere_get_image_url():\n\tFailed to parse \"%s\"\n", web_url);
		return "ERROR";
	}
	return img_src_url;
}
