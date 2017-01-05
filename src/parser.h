#include "udload.h"

/* Replace the first instance of find with replace,
 * mutating the string.
 */
void replace_first_with(char *string, char find, char replace);

/* Given the necessary information of a similar image, create a similar image
 * struct with the given values and return it.
 */
struct similar_image *create_sim_image(char *url_begin, unsigned int similarity, unsigned int x, unsigned int y);

/* Given the html contents of http://iqdb.org after an image has been uploaded,
 * get the x, y dimensions of the image and return a pointer pointing to the
 * html contents where the parsing stopped.
 */
char *parse_percent_similar(char *contents, unsigned int *similarity);

/* Given the html contents of http://iqdb.org after an image has been uploaded,
 * get the x, y dimensions of the image and return a pointer pointing to the
 * html contents where the parsing stopped.
 */
char *parse_xy_img_dimensions(char* contents, unsigned int *x, unsigned int *y);

/* Given the html contents of http://iqdb.org after an image has been uploaded,
 * parse all the results and store them in the struct similar_image_db *sim_db
 */
void populate_sim_db(struct similar_image_db *sim_db, char *html_content);


struct similar_image *get_most_similar_image(struct similar_image_db *sim_db);


/* Given the full link of a website,
 * parse the link to get the file name
 */
char *get_server_file_name(char *web_url, char stop);

char *get_image_url(char *url, char *stop_seq);


/* Frees the allocated memory for a similar_image_db */
void free_similar_image_db(struct similar_image_db *sim_db);
