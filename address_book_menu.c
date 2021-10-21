#include <stdio.h>
//#include <stdio_ext.h>  This is commented out per proffesor's instructions on Teams
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "address_book_fops.h" //Previously was "abk_fileops.h"
//#include "abk_log.h" 	Unsure what this is for, however we do not have this file and it is causing errors in the meantime.
#include "address_book_menu.h" //Previously was "abk_menus.h"
#include "address_book.h" //Previously was "abk.k"

int get_option(int type, const char *msg)
{
	/*
	 * Mutilfuction user intractions like
	 * Just an enter key detection
	 * Read an number
	 * Read a charcter
	 */ 

	/* Fill the code to add above functionality */
}

Status save_prompt(AddressBook *address_book)
{
	char option;

	do
	{
		main_menu();

		option = get_option(CHAR, "\rEnter 'N' to Ignore and 'Y' to Save: ");

		if (option == 'Y')
		{
			save_file(address_book);
			printf("Exiting. Data saved in %s\n", DEFAULT_FILE);

			break;
		}
	} while (option != 'N');

	free(address_book->list);

	return e_success;
}

Status list_contacts(AddressBook *address_book, const char *title, int *index, const char *msg, Modes mode)
{
	/* 
	 * Add code to list all the contacts availabe in address_book.csv file
	 * Should be menu based
	 * The menu provide navigation option if the entries increase the page size
	 */ 

	return e_success;
}

void menu_header(const char *str)
{
	fflush(stdout);

	system("clear");

	printf("#######  Address Book  #######\n");
	if (str != '\0')
	{
		printf("#######  %s\n", str);
	}
}

void main_menu(void)
{
	menu_header("Features:\n");

	printf("0. Exit\n");
	printf("1. Add Contact\n");
	printf("2. Search Contact\n");
	printf("3. Edit Contact\n");
	printf("4. Delete Contact\n");
	printf("5. List Contacts\n");
	printf("6. Save\n");
	printf("\n");
	printf("Please select an option: ");
}

Status menu(AddressBook *address_book)
{
	ContactInfo backup;
	Status ret;
	int option;

	do
	{
		main_menu();

		option = get_option(NUM, "");

		if ((address_book-> count == 0) && (option != e_add_contact))
		{
			get_option(NONE, "No entries found!!. Would you like to add? Use Add Contacts");

			continue;
		}

		switch (option)
		{
			case e_add_contact:
				/* Add your implementation to call add_contacts function here */
				break;
			case e_search_contact:
				search_contact(address_book);
				break;
			case e_edit_contact:
				edit_contact(address_book);
				break;
			case e_delete_contact:
				delete_contact(address_book);
				break;
			case e_list_contacts:
				break;
				/* Add your implementation to call list_contacts function here */
			case e_save:
				save_file(address_book);
				break;
			case e_exit:
				break;
		}
	} while (option != e_exit);

	return e_success;
}

Status add_contacts(AddressBook *address_book)
{
	/* Add the functionality for adding contacts here */
}

Status search(const char *str, AddressBook *address_book, int loop_count, int field, const char *msg, Modes mode)
{	
	/* Add the functionality for adding contacts here */
	
}

Status search_contact(AddressBook *address_book)
{
	char str[255];
	char line[255];
	printf("######## Search Contact: \n\n");
	printf("0. Back\n");
	printf("1. Name\n");
	printf("2. Phone No\n");
	printf("3. Email ID\n");
	printf("4. Serial No\n");

	int contactNo;
	gets(contactNo);

	FILE *fp;
	fopen(address_book, "r");
	if(fp == NULL){
		printf("File is empty or does not exist.\n");
		return e_no_match;
	}

	switch(contactNo){
		
		case 0:
			printf("Selected: Back........\nReturning to main menu....\n");
			return e_back;
		case 1: 
			//Search for name
			printf("Enter the Name:\n");
			gets(str);
			char temp[255];
			
			
			for(int i =0; i< sizeof fp +1; i++){
				fscanf(fp, "%s", temp);
				if(strcmp(str, temp)== 0){
					break;
					
				}
			}
			//if we come out of this it means it wasn't found
			return e_fail;
		
		case 2:
			//phone no.
			printf("Please enter the PHONE NUMBER of the contact you want to search for:\n");
			gets(str);
			char temp[255];
			
			
			for(int i =0; i< sizeof fp +1; i++){
				fscanf(fp, "%s", temp);
				if(strcmp(str, temp)== 0){
					break;
					
				}
			}
			return e_no_match;
		case 3:
			//email
			printf("Please enter the EMAIL of the contact you want to search for:\n");
			gets(str);
			char temp[255];
			
			
			for(int i =0; i< sizeof fp +1; i++){
				fscanf(fp, "%s", temp);
				if(strcmp(str, temp)== 0){
					break;
					
				}
			}
			return e_no_match;
			
		case 4:
			//serail no.
			printf("Please enter the SERIAL NUMBER of the contact you want to search for:\n");
			gets(str);
			
			char temp[255];
			
			for(int i =0; i< sizeof fp +1; i++){
				//word by word
				fscanf(fp, "%s", temp);
				if(strcmp(str, temp)== 0){
					break;
					
				}
			}
			return e_no_match;

		default:
			
			if(contactNo < 0 || contactNo > 4){
				printf("This is an invalid number.");
				//recursively calls it.
				search_contact(address_book);
				break;
			}


	}
	
	//print out contact

	fgets(line, "%s", address_book);
	return e_success;
	
}

Status edit_contact(AddressBook *address_book)
{
	/* Add the functionality for edit contacts here */
}

Status delete_contact(AddressBook *address_book)
{
	/* Add the functionality for delete contacts here */
}
