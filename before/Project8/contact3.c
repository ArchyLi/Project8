#include "contact3.h"

static void swap(person_p xp, person_p yp)
{
	person_t tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}
// 1->full, 0->not full
static int isContactFull(contact_p c)
{
	assert(c);

	return c->size >= c->cap ? 1 : 0;
}
//1->inc success, 0->failed 
static int incContact(contact_p c)
{
	assert(c);

	person_p new_c = realloc(c->contactList, \
		(c->cap + INC_SIZE) * sizeof(person_t));
	if (NULL == new_c) {
		perror("realloc");
		return 0;
	}
	c->contactList = new_c;
	c->cap += INC_SIZE;

	printf("room is little, inc success!\n");
	return 1;
}

void initContact(contact_pp c)
{
	assert(c);

	*c = (contact_p)malloc(sizeof(contact_t));
	if (NULL == *c) {
		perror("malloc");
		exit(1);
	}

	(*c)->contactList = (person_p)malloc(sizeof(person_t)*INIT_CONTACT_SIZE);
	if (NULL == (*c)->contactList) {
		perror("malloc");
		exit(2);
	}

	(*c)->cap = INIT_CONTACT_SIZE;
	(*c)->size = 0;

	fileLoad(*c);
}

//添加联系人的信息
void myAdd(contact_p c)
{
	assert(c);
	person_t p;
	printf("请输入姓名：");
	scanf("%s", p.name);
	printf("请输入性别：");
	scanf("%s", &p.sex);
	printf("请输入年龄：");
	scanf("%d", &p.age);
	printf("请输入电话：");
	scanf("%s", p.phone);
	printf("请输入地址：");
	scanf("%s", p.addr);
	printf("添加完毕！！\n");
	addContact(c, &p);
}



void addContact(contact_p c, person_p p)
{
	assert(c);
	assert(p);

	if (!isContactFull(c) || incContact(c)) {
		int pos = c->size;
		c->contactList[pos] = *p;
		c->size++;
	}
}
//打印所有人的信息
void showContact(contact_p c)
{
	assert(c);
	int i = 0;
	printf("打印所有联系人的信息：\n");
	printf("%-10s%-5s%-5s%-15s%-20s%\n", "姓名", "性别", "年龄", "电话", "地址");
	for (; i < c->size; i++) {
		printf("%-10s | %-5c | %-5d | %-15s | %-20s\n", c->contactList[i].name, \
			c->contactList[i].sex, c->contactList[i].age, \
			c->contactList[i].phone, c->contactList[i].addr);
	}
}

//清空所有联系人
void clearContact(contact_p c)
{
	assert(c);
	c->size = 0;
}

void delContact(contact_p c, const char *nameKey)
{
	assert(c);
	assert(nameKey);
	int i = 0;
	for (; i < c->size; i++) {
		if (strcmp(c->contactList[i].name, nameKey) == 0) {
			swap(c->contactList + i, c->contactList + c->size - 1);
			c->size--;
		}
	}
}

void print_menu()
{
	printf("*************************************************\n");
	printf("*********      通讯录 v3.0             **********\n");
	printf("*********     1、添加联系人            **********\n");
	printf("*********     2、删除联系人            **********\n");
	printf("*********     3、修改联系人            **********\n");
	printf("*********     4、搜索联系人的信息      **********\n");
	printf("*********     5、查看所有联系人        **********\n");
	printf("*********     6、清空所有联系人        **********\n");
	printf("*********     7、以名字排序所有联系人  **********\n");
	printf("*********     0、退出系统              **********\n");
	printf("*************************************************\n");
}

int fileLoad(contact_p c)
{
	assert(c);
	FILE *fp = fopen(FILE_NAME, "rb");
	if (NULL == fp) {
		perror("fopen");
		return -2;
	}

	person_t p;
	while (1) {
		fread(&p, sizeof(person_t), 1, fp);
		if (feof(fp)) {//?
			break;
		}
		addContact(c, &p);
	}

	fclose(fp);
}

int fileStore(contact_p c)
{
	assert(c);

	FILE *fp = fopen(FILE_NAME, "wb");
	if (NULL == fp) {
		perror("fopen");
		return -1;
	}

	int i = 0;
	for (; i < c->size; i++) {
		fwrite(c->contactList + i, sizeof(person_t), 1, fp);
	}

	fclose(fp);
}

void destroyContact(contact_p c)
{
	assert(c);

	fileStore(c);

	free(c->contactList);
	c->contactList = NULL;
	free(c);
	c = NULL;
}