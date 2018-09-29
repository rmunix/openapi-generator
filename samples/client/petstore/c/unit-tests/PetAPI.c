#include <stdio.h>

    #define MAX_BUFFER_LENGTH 9

    #include <stdlib.h>
    #include <string.h>
    #include <assert.h>

    #include "apiClient.h"
    #include "cJSON.h"
    #include "pet.h"
    #include "PetAPI.h"
    #include "category.h"
    #include "tag.h"

    #include "keyValuePair.h"



    #define EXAMPLE_CATEGORY_NAME "Example Category"
    #define EXAMPLE_CATEGORY_ID 5
    #define EXAMPLE_PET_NAME "Example Pet"
    #define EXAMPLE_URL_1 "http://www.github.com"
    #define EXAMPLE_URL_2 "http://www.gitter.im"
    #define EXAMPLE_TAG_1_NAME "beautiful code"
    #define EXAMPLE_TAG_2_NAME "at least I tried"
    #define EXAMPLE_TAG_1_ID 1
    #define EXAMPLE_TAG_2_ID 542353
    #define EXAMPLE_PET_ID 7867 // Set to 0 to generate a new pet

    #define EXAMPLE_OPERATION_PARAMETER 4

/*
   Creates one pet and adds it. Then gets the pet with the just added ID and compare if the values are equal.
   Could fail if someone else makes changes to the added pet, before it can be fetched again.
 */
int main() {
	printf("Hello world1\n");
	apiClient_t *apiClient = apiClient_create();

	char *categoryName = malloc(strlen(EXAMPLE_CATEGORY_NAME) + 1);
	strcpy(categoryName, EXAMPLE_CATEGORY_NAME);

	category_t *category =
		category_create(EXAMPLE_CATEGORY_ID, categoryName);

	char *petName = malloc(strlen(EXAMPLE_PET_NAME) + 1);
	strcpy(petName, EXAMPLE_PET_NAME);

	char *exampleUrl1 = malloc(strlen(EXAMPLE_URL_1) + 1);
	strcpy(exampleUrl1, EXAMPLE_URL_1);

	char *exampleUrl2 = malloc(strlen(EXAMPLE_URL_2) + 1);
	strcpy(exampleUrl2, EXAMPLE_URL_2);

	list_t *photoUrls = list_create();

	list_addElement(photoUrls, exampleUrl1);
	list_addElement(photoUrls, exampleUrl2);

	char *exampleTag1Name = malloc(strlen(EXAMPLE_TAG_1_NAME) + 1);
	strcpy(exampleTag1Name, EXAMPLE_TAG_1_NAME);
	tag_t *exampleTag1 = tag_create(EXAMPLE_TAG_1_ID, exampleTag1Name);

	char *exampleTag2Name = malloc(strlen(EXAMPLE_TAG_2_NAME) + 1);
	strcpy(exampleTag2Name, EXAMPLE_TAG_2_NAME);
	tag_t *exampleTag2 = tag_create(EXAMPLE_TAG_2_ID, exampleTag2Name);

	list_t *tags = list_create();

	list_addElement(tags, exampleTag1);
	list_addElement(tags, exampleTag2);

	char *status = "available";
	printf("Hello world2\n");
	pet_t *pet =
		pet_create(EXAMPLE_PET_ID,
		           category,
		           petName,
		           photoUrls,
		           tags,
		           status);

	PetAPI_addPet(apiClient, pet);
	printf("Hello world3\n");


}
