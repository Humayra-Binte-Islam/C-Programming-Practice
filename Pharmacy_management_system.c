#include<stdio.h>
#include <stdlib.h>
#include <string.h>

int namecheck(char name[]);
int numbercheck(char phone[]);
int usercheck(char user[]);
int checkpassword(char pass[]);
struct Medicine {
    int id;
    char name[30];
    int quantity;
    int price1;
    int price2;
};
struct Staff {
    int id;
    char name[30];
    int age;
    char post[30];
    int experience;
};

int main()
{
    int a, b, ph = 0, x, code1 = 1221;
    char input;

    printf("THIS WEBSITE IS FOR PHARMACY STAFF ONLY\n ");
    printf("\t\t\t\t\t ______________________________________\n");
    printf("\t\t\t\t\t|                                      |\n");
    printf("\t\t\t\t\t|    ***Pharmacy Control System***     |\n");
    printf("\t\t\t\t\t|______________________________________|\n");
    printf("\n1.Log in");
    printf("\n2.Create an acccount\n");
    scanf("%d", &b);

    char user[20], password[20], name[20], user1[30], password1[30], phone[11], user2[20], password2[20];



    if (b==1) {
    x:

        printf(" User name:");
        scanf("%s", user2);
        printf("\n password:");
        scanf("%s", password2);


        int found = 0;
        FILE *File = fopen("users.txt", "r");
        if (File != NULL) {
            while (fscanf(File, "%s %s", user1, password1) != EOF) {
                if (strcmp(user1, user2) == 0 && strcmp(password1, password2) == 0) {
                    found = 1;
                    break;
                }
            }
            fclose(File);
        }

        if (found == 1) {
            goto PAGE1;

        } else {
            printf("\nWrong password or User name");
            printf("\nDo you want to create an account Y/N: ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                goto v;
            } else {
                goto x;
            }
        }

    } else if (b==2) {

    v:
        printf("\n\nEnter Your Name: ");
        fflush(stdin);
        gets(name);
        int n = namecheck(name);

        if (n == 1) {
        z:
            printf("\nEnter your phone number: ");
            scanf("%s", phone);
            int nc = numbercheck(phone);
            if (nc == 1) {
            q:
                printf("User name: ");
                scanf("%s", user);
                int m = usercheck(user);
                if (m == 1) {
                r:
                    printf("Set your password : ");
                    scanf("%s", password);
                    int l = checkpassword(password);
                    if (l == 1) {
                        int code;
                        printf("TO CREATE YOUR STUFF ID WRITE DOWN THE CODE :");
                        scanf("%d", &code);
                        if (code == code1) {

                            FILE *File = fopen("users.txt", "a");
                            if(File != NULL) {
                                fprintf(File, "%s %s\n", user, password);
                                fclose(File);
                            }

                            system("cls");
                            printf("            CONGRATULATION\n");
                            printf("YOU HAVE SUCCESSFULLY CREATED THE ACCOUNT\n");
                            printf("        Welcome to the gang boy\n");
                            printf("Press 1 to go to login screen :");
                            int U;
                            scanf("%d", &U);
                            if (U == 1) goto x;
                        }
                    } else {
                        printf("PASSWORD IS INVALID (Need 8+ chars, Upper, Lower, and Digit) Try Again \n");
                        goto r;
                    }
                } else {
                    goto q;
                }
            } else {
                printf("\nINVALID NUMBER TRY AGAIN");
                goto z;
            }
        } else {
            goto v;
        }

    }

PAGE1:
    system("cls");
    printf("======MEDICINE STOCK======\n\n1.Medicine stock\n");
    printf("2.Staff information\n");
    int menu;
    scanf("%d",&menu);

    if(menu==1) {
        MEDSTOCK:
        system ("cls");
        printf ("1.Add medicine\n");
        printf ("2.Edit Medicine\n");
        printf ("3.Delete Medicine\n");
        printf ("4.view stock\n");
        printf ("5.Stock Shortage\n");
        printf ("6.Back to Menue\n");
        printf("Enter Your Choice : ");
        int choice1;
        scanf("%d",&choice1);
        struct Medicine m;
        if(choice1==1) {
            system("cls");

            FILE *fptr;
            fptr = fopen ("stock.txt", "a");
            int n;
            printf ("How many medicine do you want to add: ");
            scanf ("%d",&n);
            for (int i=0; i<n; i++) {
                printf ("\nID: ");
                scanf ("%d", &m.id);
                printf ("\nName: ");
                fflush(stdin);
                gets (m.name);
                printf ("\nQuantity: ");
                scanf ("%d", &m.quantity);
                printf ("\nCost Price: ");
                scanf ("%d", &m.price1);
                printf ("\nSelling Price:");
                scanf ("%d", &m.price2);
                fprintf(fptr ,"%d %s %d %d %d\n", m.id, m.name, m.quantity, m.price1, m.price2);
            }
            fclose(fptr);
            printf("Saved!\n");
            printf("Press 1 to go back:");
            int back;
            scanf("%d",&back);
            if(back==1) goto MEDSTOCK;

        } else if(choice1==2) {
Edit:       system("cls");
            struct Medicine m;
            int id, qnty, price1, price2, x, num ;
            char name[30];
            printf ("What Do You Want to Edit Here:\n1.Name\n2.ID\n3.Add Quantity\n4.Cost Price\n5.Selling Price\n6.Back\n\nEnter Your Choice : ");
            scanf ("%d", &x);

            system ("cls");
            if (x==1) {
               printf ("Name: ");
               fflush(stdin);
               gets (name);
            } else if (x==2) {
                printf ("ID: ");
                scanf ("%d", &id);
            } else if (x==3) {
                printf ("Add Quantity: ");
                scanf ("%d", &qnty);
            } else if (x==4) {
                printf ("Cost Price: ");
                scanf ("%d", &price1);
            } else if (x==5) {
                printf ("Selling Price: ");
                scanf ("%d", &price2);
            } else if (x=6) {
                goto MEDSTOCK;
            } else {
                printf ("\"Ivalid Input\"\n\n");
                system ("pause");
                goto Edit;
            }
            system("cls");
            FILE *oldfile=fopen("stock.txt","r");
            FILE *newfile=fopen("temp.txt","w");
            printf("To Change Enter The Medicine ID : ");
            scanf("%d",&num);
            while(fscanf(oldfile,"%d %s %d %d %d", &m.id, m.name, &m.quantity, &m.price1, &m.price2)== 5) {

                if (m.id!=num) {
                   fprintf(newfile, "%d %s %d %d %d\n", m.id, m.name, m.quantity, m.price1, m.price2);
                }
                if (m.id == num) {
                    if (x==1) {
                       fprintf(newfile, "%d %s %d %d %d\n", m.id, name, m.quantity, m.price1, m.price2 );
                    } else if (x==2) {
                       fprintf(newfile, "%d %s %d %d %d\n", id, m.name, m.quantity, m.price1, m.price2);
                    }  else if (x==3) {
                       fprintf(newfile, "%d %s %d %d %d\n", m.id, m.name, m.quantity+qnty, m.price1, m.price2);
                    } else if (x==4) {
                       fprintf(newfile, "%d %s %d %d %d\n", m.id, m.name, m.quantity, price1, m.price2);
                    } else if (x==5) {
                       fprintf(newfile, "%d %s %d %d %d\n", m.id, m.name, m.quantity, m.price1, price2);
                    }
                }
            }
            fclose(oldfile);
            fclose(newfile);
            remove("stock.txt");
            rename("temp.txt","stock.txt");
            system("cls");
            printf("Successfully Edited!\nPress 1 to Edit More\nPress Any No. to Back Medicine Stock ");
            int back; scanf("%d", &back);
            if (back==1){
                goto Edit;
            } else {
                goto MEDSTOCK;
            }

        } else if(choice1==3) {
            system("cls");
            struct Medicine m;
            int key;
            FILE *oldfile=fopen("stock.txt","r");
            FILE *newfile=fopen("temp.txt","w");
            printf("Enter the medicine ID :");
            scanf("%d",&key);
            while(fscanf(oldfile,"%d %s %d %d %d", &m.id, m.name, &m.quantity, &m.price1, &m.price2)!= EOF) {

                if(m.id!=key) {
                  fprintf(newfile, "%d %s %d %d %d\n", m.id, m.name, m.quantity, m.price1, m.price2);
                }
            }
            fclose(oldfile);
            fclose(newfile);
            remove("stock.txt");
            rename("temp.txt","stock.txt");
            printf("Deleted! Press 1 to go back: ");
            int back; scanf("%d", &back);
            if (back==1) goto MEDSTOCK;

        } else if(choice1==4) {
            system("cls");
            struct Medicine m;
            FILE *fptr;
            fptr = fopen("stock.txt", "r");
            if (fptr == NULL)
            {
                printf("No records!");
            } else {
                printf("\n%-10s %-20s %-10s %-15s %s\n", "ID", "Name", "Qty", "Cost Price", "Selling Price");
                printf("-------------------------------------------------------------------------\n");

                while(fscanf(fptr, "%d %s %d %d %d", &m.id, m.name, &m.quantity, &m.price1, &m.price2)== 5) {

                    printf("%-10d %-20s %-14d %-16d %d\n", m.id, m.name, m.quantity, m.price1, m.price2);

                }
            }
            fclose (fptr);
            printf("\nPress 1 to go back: ");
            int back;
            scanf("%d", &back);
            if(back == 1) goto MEDSTOCK;

        } else if (choice1==5) {
            system("cls");
            struct Medicine m;
            FILE *fptr;
            fptr = fopen("stock.txt", "r");
            if (fptr == NULL)
            {
                printf("No records!");
            } else {
                printf("\n%-10s %-20s %-10s %-15s %s\n", "ID", "Name", "Qty", "Cost Price", "Selling Price");
                printf("-------------------------------------------------------------------------\n");

                while(fscanf(fptr, "%d %s %d %d %d", &m.id, m.name, &m.quantity, &m.price1, &m.price2)== 5) {

                    if (m.quantity < 20) {
                    printf("%-10d %-20s %-14d %-16d %d\n", m.id, m.name, m.quantity, m.price1, m.price2);
                    }
                }
            }
            fclose (fptr);
            printf("\nPress 1 to go back: ");
            int back;
            scanf("%d", &back);
            if(back == 1) goto MEDSTOCK;

        } else  if(choice1==6) {
           goto PAGE1;
        }

    } else if (menu == 2) { // STAFF SECTION
        PHARM:
        system("cls");
        printf("===== STAFF MANAGEMENT =====\n\n");
        printf("1. Recruite a Staff\n");
        printf("2. Fire a Staff\n");
        printf("3. View all Staff\n");
        printf("4. Back to Main Menu\n");
        printf("Enter Choice: ");

        int choice2;
        scanf("%d", &choice2);
        system("cls");
        if (choice2 == 1) {
            struct Staff s;
            FILE *fptr = fopen("staff.txt", "a");

            if (fptr == NULL) {
                printf("Error: Could not open file!\n");
            } else {
                printf("\n--- Enter New Staff Details ---\n");
                printf ("ID: ");
                scanf ("%d", &s.id);
                printf("Name: ");
                fflush(stdin);
                gets(s.name);
                printf("Age: ");
                scanf("%d", &s.age);
                printf("Post: ");
                fflush(stdin);
                gets(s.post);
                printf("Experience (Years): ");
                scanf("%d", &s.experience);
                fprintf(fptr, "%d %s %d %s %d\n", s.id, s.name, s.age, s.post, s.experience);
                fclose(fptr);
                printf("\nSuccessfully Saved!\n");
            }
            system("pause");
            goto PHARM;

        } else if (choice2 == 2) {
            system("cls");
            struct Staff s;
            int id;
            printf ("To Fire a Staff \nEnter Staff ID: ");
            scanf ("%d", &id);
            FILE *oldfptr = fopen ("staff.txt", "r");
            FILE *newfptr = fopen ("temp.txt", "w");

            while (fscanf(oldfptr, "%d %s %d %s %d", &s.id, &s.name, &s.age, &s.post, &s.experience)!=EOF) {

                if (id != s.id) {
                    fprintf (newfptr, "%d %s %d %s %d\n", s.id, s.name, s.age, s.post, s.experience);
                }
            }

            fclose (oldfptr);
            fclose (newfptr);
            remove ("staff.txt");
            rename ("temp.txt", "staff.txt");
            printf ("\nThe Stuff is Fired!\n\n");
            system("pause");
            goto PHARM;

        } else if (choice2 == 3) {
             struct Staff s;
            FILE *fptr = fopen("staff.txt", "r");

            if (fptr == NULL) {
                printf("\nNo records found! Add a pharmacist first.\n");
            } else {
                printf("\n%-10s %-20s %-5s %-15s %s\n","ID", "NAME", "AGE", "POST", "EXP.");
                printf("--------------------------------------------------------------------\n");


                while (fscanf(fptr, "%d %s %d %s %d", &s.id, &s.name, &s.age, &s.post, &s.experience) != EOF) {
                    printf("%-10d %-20s %-5d %-15s %-d years\n",s.id, s.name, s.age, s.post, s.experience);
                 }
                fclose(fptr);
            }
            printf("\n");
            system("pause");
            goto PHARM;

        } else {

            goto PAGE1;
        }
    }
}



int namecheck(char name[])
{
    int x, ch = 0;
    for (x = 0; name[x] != '\0'; x++) {

        if (!((name[x] >= 'a' && name[x] <= 'z') || (name[x] >= 'A' && name[x] <= 'Z') || name[x] == ' ')) {
            ch++;
        }
    }
    if (ch == 0) return 1;
    else return 2;
}

int numbercheck(char phone[])
{
    int a = 0, b;
    if (strlen(phone) != 11) return 2;
    if (phone[0] == '0' && phone[1] == '1') {
        a = 2;
        for (b = 2; b < 11; b++) {
            if (phone[b] >= '0' && phone[b] <= '9') {
                a++;
            }
        }
    }
    if (a == 11) return 1;
    else return 2;
}

int usercheck(char user[])
{
    if (user[0] != '\0') {
        return 1;
    }
    return 2;
}

int checkpassword(char pass[])
{
    int a = strlen(pass);
    if (a >= 8) {
        int cc = 0, sc = 0, d = 0;
        for (int x = 0; pass[x] != '\0'; x++) {
            if (pass[x] >= 'A' && pass[x] <= 'Z') cc++;
            else if (pass[x] >= 'a' && pass[x] <= 'z') sc++;
            else if (pass[x] >= '0' && pass[x] <= '9') d++;
        }
        if (sc > 0 && cc > 0 && d > 0) return 1;
    }
    return 2;
}
