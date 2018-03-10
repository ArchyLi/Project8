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

//�����ϵ�˵���Ϣ
void myAdd(contact_p c)
{
	assert(c);
	person_t p;
	printf("������������");
	scanf("%s", p.name);
	printf("�������Ա�");
	scanf("%s", &p.sex);
	printf("���������䣺");
	scanf("%d", &p.age);
	printf("������绰��");
	scanf("%s", p.phone);
	printf("�������ַ��");
	scanf("%s", p.addr);
	printf("�����ϣ���\n");
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
//��ӡ�����˵���Ϣ
void showContact(contact_p c)
{
	assert(c);
	int i = 0;
	printf("��ӡ������ϵ�˵���Ϣ��\n");
	printf("%-10s%-5s%-5s%-15s%-20s%\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (; i < c->size; i++) {
		printf("%-10s | %-5c | %-5d | %-15s | %-20s\n", c->contactList[i].name, \
			c->contactList[i].sex, c->contactList[i].age, \
			c->contactList[i].phone, c->contactList[i].addr);
	}
}

//���������ϵ��
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
	printf("*********      ͨѶ¼ v3.0             **********\n");
	printf("*********     1�������ϵ��            **********\n");
	printf("*********     2��ɾ����ϵ��            **********\n");
	printf("*********     3���޸���ϵ��            **********\n");
	printf("*********     4��������ϵ�˵���Ϣ      **********\n");
	printf("*********     5���鿴������ϵ��        **********\n");
	printf("*********     6�����������ϵ��        **********\n");
	printf("*********     7������������������ϵ��  **********\n");
	printf("*********     0���˳�ϵͳ              **********\n");
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