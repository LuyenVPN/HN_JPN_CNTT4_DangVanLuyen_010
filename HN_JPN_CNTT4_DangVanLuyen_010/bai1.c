#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[100];
    float price;
    char author[50];
    char category[30];
    char date[20];
}Book;

typedef struct listBook {
    Book book;
    struct listBook *next;
    struct listBook *prev;
}listBook;
listBook *headBook=NULL;
typedef struct passBook {
    Book book;
    struct passBook *next;
}passBook;
passBook *headPass=NULL;
int countId=1;

listBook *createBook(Book book) {
    listBook *newBook= (listBook *)malloc(sizeof(listBook));
    newBook->book= book;
    newBook->next=NULL;
    newBook->prev=NULL;
}
listBook *addBook(listBook *head, Book book) {
    listBook *newNode=createBook(book);
    if (head == NULL) {
        return newNode;
    }
    listBook *temp=head;
    while (temp->next != NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}
void displayBook(listBook *head){
    if(head== NULL) {
        printf("Chua co sac");
        return;
    }
    listBook *temp=head;
    while (temp!=NULL){
        printf("%d| %s | %f | %s | %s | %s \n", temp->book.id, temp->book.title, temp->book.price, temp->book.author,temp->book.category,temp->book.date);
        temp=temp->next;
    }
}
int deleteBook(listBook *head, int id) {
    if(head==NULL) {
        printf("chua co sach");
        return head;
    }
    listBook *temp=head;
    while (temp!=NULL&& temp->book.id!= id){
        temp=temp->next;
    }
    if(temp== NULL) {
        printf("khong thay");
        return head;
    }
    if(temp->prev== NULL) {
        head=temp->next;
    if(head !=NULL){
        head->prev=NULL;
    }
    }else {
        temp->prev->next=temp->next;
        if(temp->next==NULL) {
            temp->next->prev=temp->prev;
        }
    }
    free(temp);
    return head;
}
void updateBook(listBook *head, int data){
    if(head== NULL) {
        printf("chua co sach");
        return;
    }
    listBook *temp=head;
    while(temp!=NULL&& temp->book.id !=data) {
        temp=temp->next;
    }
    if(temp== NULL) {
        printf("khong thay");
        return;
    }
    printf("Title: ");
    gets(temp->book.title);
    fflush(stdin);
    printf("Price: ");
    scanf("%f",&temp->book.price);
    fflush(stdin);
    printf("Author:");
    gets(temp->book.author);
    fflush(stdin);
    printf("Category: ");
    gets(temp->book.category);
    fflush(stdin);
    printf("Date: ");
    gets(temp->book.date);
    fflush(stdin);
}
void sreachBook(listBook *head, char*key) {
    listBook *temp=head;
    int found=0;
    while (temp) {
        if(strcmp(temp->book.title,key)==0) {
            printf("%d| %s | %f | %s | %s | %s \n", temp->book.id, temp->book.title, temp->book.price, temp->book.author,temp->book.category,temp->book.date);
            found=-1;
        }
        temp=temp->next;
    }
    if(found==0) {
        printf("khong thay");
    }
}
void menu() {
    int choice;
    do {
        printf("\n>>>>>>>>>>Book Store Manager<<<<<<<<<\n");
        printf("1. Them Sach\n");
        printf("2. Hien thi danh sach ca quyen\n");
        printf("3. Xoa Sach\n");
        printf("4. Cap nhat thong tin sach\n");
        printf("5. Danh dau cho thue\n");
        printf("6. Sap xep sach (Theo ten tac gia\n");
        printf("7. Tim kiem sach (theo ten)\n");
        printf("8. Thoat\n");
        printf("Nhap Lua Chon: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                Book b;
                b.id=countId++;
                printf("Title: ");
                gets(b.title);
                fflush(stdin);
                printf("Price: ");
                scanf("%f",&b.price);
                fflush(stdin);
                printf("Author:");
                gets(b.author);
                fflush(stdin);
                printf("Category: ");
                gets(b.category);
                fflush(stdin);
                printf("Date: ");
                gets(b.date);
                fflush(stdin);
                headBook=addBook(headBook,b);
                break;
            case 2:
                displayBook(headBook);
                break;
            case 3:
                int iddel;
                printf("Nhap id can xoa: ");
                scanf("%d", &iddel);
                headBook=deleteBook(headBook,iddel);
                break;
            case 4:
                int idUpdate;
                printf("Nhap id can cap nhat:");
                scanf("%d",&idUpdate);
                fflush(stdin);
                updateBook(headBook,idUpdate);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                char search[50];
                printf("Nhap ten can tim:");
                gets(search);
                fflush(stdin);
                sreachBook(headBook,search);
                break;
            case 8:
                printf("Thoat Chuong Trinh");
                return;
                default:
                printf("Lua chon khong hop le");
        }
    }while (choice!=8);
}
int main() {
    menu();
    return 0;
}