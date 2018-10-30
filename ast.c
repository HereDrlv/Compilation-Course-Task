#include "def.h"
struct node * mknode(int kind,struct node *first,struct node *second, struct node *third,int pos ) {
  struct node *T=(struct node *)malloc(sizeof(struct node));
  T->kind=kind;
  T->ptr[0]=first;
  T->ptr[1]=second;
  T->ptr[2]=third;
  T->pos=pos;
  return T;
}

void display(struct node *T,int indent)  {//traverse the tree 
  int i=1;
  struct node *T0;
  if (T)
	{
	switch (T->kind) {
	case EXT_DEF_LIST:  display(T->ptr[0],indent);    //display first one in the external define list  
                        display(T->ptr[1],indent);    //display others  
                        break;
	case EXT_VAR_DEF:   printf("%*c external variaty define  :\n",indent,' ');
                        display(T->ptr[0],indent+3);        //display  external variaty type
                        printf("%*cvariaty name  :\n",indent+3,' ');
                        display(T->ptr[1],indent+6);        //display variaty list 
                        break;
	case TYPE:          printf("%*ctype : %s\n",indent,' ',T->type_id);
                        break;
    case EXT_DEC_LIST:  display(T->ptr[0],indent);     //display  external variaty names ，
                        display(T->ptr[1],indent);     
                        break;
	case FUNC_DEF:      printf("%*cfunction define  :\n",indent,' ');
                        display(T->ptr[0],indent+3);      //display function return type
                        display(T->ptr[1],indent+3);      //display function name  and para 
                        display(T->ptr[2],indent+3);      //display function body 
                        break;
	case FUNC_DEC:      printf("%*cfunction name  :%s\n",indent,' ',T->type_id);
                        if (T->ptr[0]) {
                                printf("%*cfunction formal para :\n",indent,' ');
                                display(T->ptr[0],indent+3);  //display function para list 
                                }
                        else printf("%*cnon-para function \n",indent+3,' ');
                        break;
	case PARAM_LIST:    display(T->ptr[0],indent);     //display  all para type and name ，
                        display(T->ptr[1],indent);
                        break;
	case PARAM_DEC:     printf("%*ctype :%s, para name  :%s\n", indent,' ',  \
                               T->ptr[0]->type==INT?"int": "float",T->ptr[1]->type_id);
                        break;
	case EXP_STMT:      printf("%*cexp  sentence  :\n",indent,' ');
                        display(T->ptr[0],indent+3);
                        break;
	case RETURN:        printf("%*creturn  sentence  :\n",indent,' ');
                        display(T->ptr[0],indent+3);
                        break;
	case COMP_STM:      printf("%*ccomposite sentence  :\n",indent,' ');
                        printf("%*ccomposite sentence variaty define  :\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      //display define part
                        printf("%*ccomposite sentence sentence part :\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //display  sentence part
                        break;
	case STM_LIST:      display(T->ptr[0],indent);      //display the first sentence 
                        display(T->ptr[1],indent);        //display rest sentence 
                        break;
	case WHILE:         printf("%*cwhile loop  sentence  :\n",indent,' ');
                        printf("%*cwhile loop condition  :\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      //display loop condition 
                        printf("%*cwhile loop body  :\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //display loop body 
                        break;
    case FOR://here 
                        printf("%*cfor loop  sentence  :\n",indent,' ');
                        printf("%*cfor loop condition  :\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //display loop condition 
                        printf("%*cfor loop body  :\n",indent+3,' ');
                        display(T->ptr[2],indent+6);      //display loop body 
                        break;
	case IF_THEN:       printf("%*ccondition  sentence (IF_THEN) :\n",indent,' ');
                        printf("%*ccondition  :\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      //display condition 
                        printf("%*cIF sentence :\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //display if sentence
                        break;
	case IF_THEN_ELSE:  printf("%*ccondition  sentence (IF_THEN_ELSE) :\n",indent,' ');
                        printf("%*ccondition  :\n",indent+3,' ');
                        display(T->ptr[0],indent+6);      //display condition 
                        printf("%*cIF sentence :\n",indent+3,' ');
                        display(T->ptr[1],indent+6);      //display if sentence
                        printf("%*cELSE sentence :\n",indent+3,' ');
                        display(T->ptr[2],indent+6);      //display else sentence
                        break;
    case DEF_LIST:      display(T->ptr[0],indent);    //display the first one of local variaty define list 
                        display(T->ptr[1],indent);    //display others 
                        break;
    case VAR_DEF:       printf("%*cLOCAL VAR_NAME :\n",indent,' ');
                        display(T->ptr[0],indent+3);   //display variaty type
                        display(T->ptr[1],indent+3);   //display the define 的 all variaty name 
                        break;
    case DEC_LIST:      printf("%*cVAR_NAME :\n",indent,' ');
                        T0=T;
                        while (T0) {
                            if (T0->ptr[0]->kind==ID)
                                printf("%*c %s\n",indent+3,' ',T0->ptr[0]->type_id);
                            else if (T0->ptr[0]->kind==ASSIGNOP)
                                {
                                printf("%*c %s ASSIGNOP\n ",indent+3,' ',T0->ptr[0]->ptr[0]->type_id);
							//display init exp 
                                display(T0->ptr[0]->ptr[1],indent+strlen(T0->ptr[0]->ptr[0]->type_id)+4);       
                                }
                            T0=T0->ptr[1];
                            }
                        break;
	case ID:	        printf("%*cID : %s\n",indent,' ',T->type_id);
                        break;
	case INT:	        printf("%*cINT :%d\n",indent,' ',T->type_int);
                        break;
	case FLOAT:	        printf("%*cFLAOT :%f\n",indent,' ',T->type_float);
                        break;
	case CHAR:	        printf("%*cCHAR :%s\n",indent,' ',T->type_char);
                        break;
	case ASSIGNOP:
    case PLUSASS:
    case MINUSASS:
	case AND:
	case OR:
	case RELOP:
	case PLUS:
	case MINUS:
	case STAR:
	case DIV:
                    printf("%*c%s\n",indent,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    display(T->ptr[1],indent+3);
                    break;
	case NOT:
	case UMINUS:    printf("%*c%s\n",indent,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    break;
    case FUNC_CALL: printf("%*cfunction call :\n",indent,' ');
                    printf("%*cfunction name  :%s\n",indent+3,' ',T->type_id);
                    display(T->ptr[0],indent+3);
                    break;
	case ARGS:      i=1;
                    while (T) {  //ARGS表示 actual para exp 序列结点，其第一棵子树为其一个 actual para exp ，第二棵子树为rest的。
                        struct node *T0=T->ptr[0];
                        printf("%*c %dth actual para exp  :\n",indent,' ',i++);
                        display(T0,indent+3);
                        T=T->ptr[1];
                        }
//                    printf("%*c %dth actual para exp  :\n",indent,' ',i);
  //                  display(T,indent+3);
                    printf("\n");
                    break;
         }
      }
}
