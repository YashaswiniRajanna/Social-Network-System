#include <stdio.h>
#include <string.h>
#define MAX 50
int n;
int graph[MAX][MAX];
int queue[MAX], f=-1, r=-1;
void insert(int data)
{
	r=(r+1)%MAX;
	queue[r]=data;
	if(f==-1)
	f=0;
	if(f==-1
 }
  int isempty()
{
		if(f==-1)
		return 1;
		return 0;

}
int Delete()
{
	int data;
    data=queue[f];
   if(f==r)
       f=r=-1;
   else
       f=(f+1)%MAX;
       return data;
}
struct message
{

	char received[MAX][100];
	int r;
	char from[MAX][20];
	char sent[MAX][100];
	int s;
	char to[MAX][20];
};
struct user
{
	char user_name[20];
	int user_id;
	char password[20];
	char place[20];
	char profession[20];
	char email[20];
	struct message m;
}u[MAX];
void display_users(void)
{
	int i;
	printf("\n\n\n");
	printf("\tUSER NAME\t\tUSER ID\n");
	printf("\t---------\t\t ------\n");
	for(i=0;i<n;i++)
	{
	printf("\t%-15s\t\t %02d\n",u[i].user_name,i);
	}
	printf("\n\n\n");
}
void display_connections(int v)
{
	int i;
	printf("\tUSER NAME\t\tUSER ID\n");
	printf("\t---------\t\t ------ \n");
	for(i=0;i<n;i++)
	{
	if(graph[v][i]==1)
	{
	printf("\t%-15s\t\t %02d\n",u[i].user_name,i);
	}
	}
	printf("\n\n\n");
}
void display_suggestions(int v)
{
int marked[MAX], level[MAX];
int frontvertex;
	int i, b;
	insert(v);
	for(i=0;i<n;i++)
	marked[i]=0;
level[v] = 0;
    marked[v] = 1;
while (!isempty())
{
	v = Delete();
	for (i=0; i<n; i++)
   {
   b = graph[v][i];
       if (b&&!marked[i])
{
insert(i);
level[i]=level[v] + 1;
marked[i]=1;
   }
  }
}
printf("\tUSER NAME\t\tUSER ID\t\tCONNECTION LEVEL\n");
printf("\t \t\t \t\t \n");
for (i=0; i<n; i++)
{
if(level[i]>1||marked[i]==0)
 {
if(marked[i]==0)
	printf("\t%-15s\t\t %02d\t\tno connection
	link\n",u[i].user_name,u[i].user_id);
else
	printf("\t%-15s\t\t
	%02d\t\t\t%02d\n",u[i].user_name,u[i].user_id,level[i]);
  }
}
  printf("\n\n\n");
}
void mutual_friends(int v1, int v2)
{
	int i;
	printf("\tUSER NAME\t\tUSER ID\n");
	printf("\t---------\t\t ------ \n");
	for(i=0;i<n;i++)
	{
	if(graph[v1][i]==1 && graph[v2][i]==1)
	printf("\t%-15s\t\t %02d\n",u[i].user_name,i);
	}
	printf("\n\n\n");
	}
void shortest_path(int v1, int v2)
{
	int visited[MAX], distance[MAX], parent[MAX], path[MAX];
	int i, front, x;
	for(i=0;i<n;i++)
	{
	distance[i]=0;
	visited[i]=0;
	}
	visited[v1]=1;
	parent[v1]=-1;
	insert(v1);
	while(!isempty())
	{
	front = Delete();
	for(i=0;i<n;i++)
	{
	if(graph[front][i] && !visited[i])
	{
	visited[i]=1;
	insert(i);

	distance[i]=distance[front]+1;
	parent[i]=front;
    }
  }
}
if(visited[v2]==0)
  printf("\nNo link between you and %s\n",u[v2].user_name);
else
{
 x=v2;
 i=0;
while(x!=-1)
{
	path[i++]=x;
	x=parent[x];
}
printf("\nShortest link between you and %s\n\n%s",u[v2].user_name,u[path[--i]].user_name);
while(i)
{
  printf(" -> %s",u[path[--i]].user_name);
}
 printf("\n\n");
  }
}
void send_message(int s, int r)
{
	char message[100], name[20];
	printf("\n\nEnter your message(use '_' instead of spaces): ");
	scanf("%s",u[r].m.received[(u[r].m.r)++]);
	strcpy(u[r].m.from[(u[r].m.r)-1],u[s].user_name);
	strcpy(u[s].m.sent[(u[s].m.s)++],u[r].m.received[(u[r].m.r)-1]);
	strcpy(u[s].m.to[(u[s].m.s)-1],u[r].user_name);
	printf("\nMessage sent successfully!!!");
	printf("\n\n\n");
}
void display_messages(int id)
{
	int c, i;
	printf("\n\n\n");
	printf(" \n");
	printf("1.SENT MESSAGES\n");
	printf(" \n");
	printf("2.RECEIVED MESSAGES\n");
	printf("\nEnter your choice : "); scanf("%d",&c);
if(c==1)
{
	printf("\n\n----------------- SENT MESSAGES------------------\n\n");
	for(i=0;i<u[id].m.s;i++)
	{
	printf("to %s : %s\n",u[id].m.to[i],u[id].m.sent[i]);
	}
	if(u[id].m.s==0)
	printf("No messages to display\n");
}

else
{
	printf("\n\n----------------- RECEIVED MESSAGES------------------\n\n");
	for(i=0;i<u[id].m.r;i++)
	{
	printf("from %s : %s\n",u[id].m.from[i],u[id].m.received[i]);
	}
	if(u[id].m.r==0)
	printf("No messages to display\n");
  }
  printf("\n\n");
}
int main()
{
	FILE *fp1, *fp2;
	int i, j, choice, id, id2;
	char password[20], password2[20];
	fp1=fopen("graph.txt","r");
if(fp1!=NULL)
 { 
   if(feof(fp1)==0)
    {
     fscanf(fp1,"%d",&n);
     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
          {
            if(feof(fp1)==0)
          }
      }
}
fclose(fp1);
}
fscanf(fp1,"%d",&graph[i][j]);
fp2=fopen("users.txt","r");
if(fp2!=NULL)
{
for(i=0;i<n;i++)
{
fscanf(fp2,"%s%d%s%s%s%s",u[i].user_name,&u[i].user_id,u[i].password,u[i].place,u[i].profession,u[i].e
mail);
}
fclose(fp2);
}
printf("\n\n\n");
printf("\t\t\t\t\t \n");
printf("\t\t\t\t\t| WELCOME |\n");
printf("\t\t\t\t\t \n");
label1:
printf("\n\n\n");
printf(" \n");
printf("1.CREATE ACCOUNT\n");
printf(" \n");
printf("2.LOGIN\n");
SOCIAL NETWORKING
Dept of CSE, SIT, TUMKUR
12
printf(" \n");
printf("3.DISPLAY ALL USERS\n");
printf(" \n");
printf("4.EXIT\n");
printf("\nEnter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: printf("\nEnter your user name : ");
		scanf("%s",u[n].user_name);
		printf("Enter password : ");
		scanf("%s",password);
		printf("Confirm your password : ");
		scanf("%s",password2);
		if(strcmp(password,password2)!=0)
		{
		printf("Password didn't match!!!\n");
		printf("Failed to create account. Redirecting to main menu...\n");
		goto label1;
		}
		strcpy(u[n].password,password);
		u[n].user_id=n;
		id=n;
		printf("\nEnter your personal information: \n");
		printf("Place : "); scanf("%s",u[id].place);
		printf("Profession : "); scanf("%s",u[id].profession);
		printf("Email : "); scanf("%s",u[id].email);
		printf("\nAccount created successfully!!!\n");
		printf("Your user_id is: %d\n",u[n].user_id);
		n++;
		printf("\nYou can login to your account using your user_id and password\n\n");
		for(i=0;i<n;i++)
		{
		graph[id][i]=0;
		graph[i][id]=0;
		}
		goto label1;
		break;
case 2: printf("Enter your user_id: ");
		scanf("%d",&id);
		printf("Enter your password: ");
		scanf("%s",password);
		if(strcmp(password,u[id].password)==0)
		{
		printf("\nYou are successfully logged into your account!!!\n");
		}
		else
		{
		printf("Wrong Password!!! Redirecting to main menu...\n");
		goto label1;
		}
		break;
case 3: display_users();
	  goto label1;
     	break;
default: goto label5;
}
printf("\n\n\n\n");
printf("\n");
printf("======================= %s ========================\n",u[id].user_name);
printf("\t\tPlace : %s\n\t\tProfession : %s\n\t\tEmail : %s\n\n",u[id].place,u[id].profession,u[id].email);
label2:
printf(" \n");
printf("1.Display my connections\n");
printf(" \n");
printf("2.Display friend suggestions\n");
printf(" \n");
printf("3.View a profile\n");
printf(" \n");
printf("4.Send a connection request\n");
printf(" \n");
printf("5.Edit my profile\n");
printf(" \n");
printf("6.View my messages\n");
printf(" \n");
printf("7.Log out\n");
printf("\n\nEnter your choice: "); scanf("%d",&choice);
switch(choice)
{
case 1: printf("\n\n\n");
	printf("---------------- MY CONNECTIONS ---------------- \n\n");
	display_connections(id);
	goto label2;
     break;
case 2: printf("\n\n\n");
	printf("---------------- SUGGESTIONS ---------------- \n\n");
	display_suggestions(id);
	goto label2;
	break;
case 3: printf("\n\n\n");
	printf("Enter the user_id of the profile you would like to view: ");
	scanf("%d",&id2);
	label3:
	printf("\n\n\n");
	printf("====================== %s
	==========================\n",u[id2].user_name);
	printf("\t\tPlace : %s\n\t\tProfession : %s\n\t\tEmail :
	%s\n\n\n",u[id2].place,u[id2].profession,u[id2].email);
	printf(" \n");
	printf("1.Send a connection request\n");
	printf(" \n");
	printf("2.View mutual friends\n");
	printf(" \n");
	printf("3.View shortest link\n");
	printf(" \n");
	printf("4.Send a message\n");
	printf(" \n");
	printf("5.Return to previous menu\n");
	printf("\n\nEnter your choice: "); scanf("%d",&choice);
switch(choice)
{
case 1: if(graph[id][id2]==1)
		{
		printf("\nYou are already friends with %s\n",u[id2].user_name);
		SOCIAL NETWORKING
		Dept of CSE, SIT, TUMKUR
		14
		goto label3;
		}
		else
		{
		graph[id][id2]=graph[id2][id]=1;
		printf("You and %s are now friends\n",u[id2].user_name);
		}
		goto label3;
		break;
case 2: printf("\n\n-----------------MUTUAL FRIENDS---------------- \n");
	    mutual_friends(id, id2);
	    goto label3;
	    break;
case 3: shortest_path(id, id2);
	  goto label3;
	  break;
case 4: send_message(id, id2);
	goto label3;
	break;
default : goto label2;
}
break;
	case 4: printf("Enter the user_id of the person u would like to connect: ");
	scanf("%d",&id2);
	if(graph[id][id2]==1)
	{
	printf("You are already friends with %s\n",u[id2].user_name);
	goto label2;
	}
else
{
	graph[id][id2]=graph[id2][id]=1;
	printf("You and %s are now friends\n",u[id2].user_name);
}
     goto label2;
     break;
	case 5: label4:
	printf("\n\n---------------- EDIT PROFILE----------------- \n");
	printf(" \n");
	printf("1.Edit user_name\n");
	printf(" \n");
	printf("2.Edit password\n");
	printf(" \n");
	printf("3.Edit email\n");
	printf(" \n");
	printf("4.Return to previous menu\n");
	printf("\n\nEnter your choice: "); scanf("%d",&choice);
	switch(choice)
{
case 1: printf("Enter the new user_name: "); scanf("%s",u[id].user_name);
		printf("user_name updated successfully!!!\n");
		goto label4;
		break;
		case 2: printf("Enter your current password: "); scanf("%s",password);
		if(strcmp(password,u[id].password)==0)

{
printf("\nEnter your new Password: "); scanf("%s",password);
printf("\nConfirm your password: "); scanf("%s",password2);
if(strcmp(password,password2)!=0)
{
  printf("Password didn't match!!!\n");
}
else
{
	strcpy(u[n].password,password);
	printf("Password updated successfully\n");
}
}
else
{
printf("Wrong Password!!!\n");
}
  goto label4;
  break;
case 3: printf("Enter the new emaid id: "); scanf("%s",u[id].email);
	printf("Email updated successfully!!!\n");
	goto label4;
	break;
	default : printf("\n\n\n");
	goto label2;
}
	case 6: display_messages(id);
	goto label2;
	default : printf("\nLogged out successfully!!\n\n");
	goto label1;
	}
	label5:
	fp1=fopen("graph.txt","w");
	fprintf(fp1,"%d\n",n);
	for(i=0;i<n;i++)
	{
	for(j=0;j<n;j++)
	{
	fprintf(fp1,"%d ",graph[i][j]);
	}
	fprintf(fp1,"\n");
	}
	fclose(fp1);
	fp2=fopen("users.txt","w");
	for(i=0;i<n;i++)
	{
	fprintf(fp2,"%s %d %s %s %s
	%s\n",u[i].user_name,u[i].user_id,u[i].password,u[i].place,u[i].profession,u[i].email);
	}
	fclose(fp2);
return 0;
}
