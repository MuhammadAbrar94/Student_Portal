#include<stdio.h>
#include<string.h>
#include<conio.h>

int main(void)
{
    FILE *fp;

    char valid = 'Y';
    int t_lenght,position;
    char teacher_id[30];
    char student_id[30];
    char subject[30];
    char batch[5]="";
    char degree[5]="";
    char roll_no[5];
    int teacher_pas;
    fp = fopen("data.txt","r+");
    if (fp==NULL)
    {
        printf("Error");
    }
    fseek(fp,0,2);
    while (valid=='Y' || valid=='y')
    {
        int n,n_student,k,i;
        printf("\nEnter the Teacher id: ");
        scanf("%s",teacher_id);
        fflush(stdin);
        printf("\nName of subject this teacher is teaching: ");
        gets(subject);
        fflush(stdin);
        printf("\nHow many student you want to Register in this class: ");
        scanf("%d",&n_student);
        fflush(stdin);
        printf("\nEnter batch of Students: ");
        scanf("%s",batch);
        fflush(stdin);
        printf("\nEnter degree: ");
        scanf("%s",degree);
        fflush(stdin);
        t_lenght = 29-strlen(teacher_id);//This line is for finding the last bytes of string out of 30
        position = strlen(teacher_id); // This line is for finding the
        position = position+t_lenght;
        for (k=1;k<=n_student;k++)
        {

            itoa(k,roll_no,10);
            if (strlen(roll_no)==1)
            {
                strcat(roll_no,"00");
            }
            else if (strlen(roll_no)==2)
            {
            strcat(roll_no,"0");
            }
            strcat(strcat(strcat(strcat(strcpy(student_id,batch),"-"),degree),"-"),roll_no);
            fputs(teacher_id,fp);
            position = ftell(fp)+t_lenght;
            fseek(fp,position,0);
            position = position+30;
            fputs(student_id,fp);
            fseek(fp,position,0);
            fputs(subject,fp);
            fseek(fp,position+150,0);
            fputs("\n",fp);
            if (k==n_student)
            {
                for (i=0;i<219;i++)
                {
                    fputs("0",fp);
                }
                fputs("\n",fp);
            }
        }
        printf("Do you want to enter another Teacher record? (Y/N): ");
        fflush(stdin);
        scanf("%c",&valid);

    }
        fclose(fp);
}
