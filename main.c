  #include <calculator_operations.h>
  #include <math.h>

/* Status of the operation requested */
#define VALID   (1)
#define INVALID (0)

/* Calculator operation requested by user*/
unsigned int calculator_operation = 0;

/* Operands on which calculation is performed */
int calculator_operand1 = 0;
int calculator_operand2 = 0;

/* Valid operations */
enum operations{ ADD=1, SUBTRACT, MULTIPLY, DIVIDE, POWER, SQUARE_ROOT, FACTORIAL, INVERSE, CURRENCY, LENGTH, EXIT };

/* Display the menu of operations supported */
void calculator_menu(void);
/* Verifies the requested operations validity */
int valid_operation(int operation);


/* Start of the application */
int main(int argc, char *argv[])
{
    printf("\n****Calculator****\n");
    while(1)
    {
        calculator_menu();
    }
}

void calculator_menu(void)
{
    printf("\nAvailable Operations\n");
    printf("\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Power\n6. Square_root\n7. Factorial\n8. Inverse\n9. Currency\n10. Length\n11. Exit");
    printf("\n\tEnter your choice\n");
   
     __fpurge(stdin);
    scanf("%d", &calculator_operation);

    if(EXIT == calculator_operation)
    {
        printf("\nThank you. Exiting the Application\n");
        exit(0);
    }

    if(INVALID != valid_operation(calculator_operation))
    {
        printf("\n\tEnter your Numbers with space between them\n");
        __fpurge(stdin);
        scanf("%d %d", &calculator_operand1, &calculator_operand2);
    }
    else
    {
        printf("\n\t---Wrong choice---\nEnter to continue\n");
        __fpurge(stdin);
        getchar();
        return;
        
    }
    switch(calculator_operation)
    {
        case ADD:
            printf("\n\t%d + %d = %d\nEnter to continue", 
            calculator_operand1, 
            calculator_operand2,
            add(calculator_operand1, calculator_operand2));
            
            __fpurge(stdin);
            getchar();
            break;
        case SUBTRACT:
            printf("\n\t%d - %d = %d\nEnter to continue", 
            calculator_operand1, 
            calculator_operand2,
            subtract(calculator_operand1, calculator_operand2));
            
            __fpurge(stdin);
            getchar();
            break;
        case MULTIPLY:
            printf("\n\t%d * %d = %d\nEnter to continue", 
            calculator_operand1, 
            calculator_operand2,
            multiply(calculator_operand1, calculator_operand2));
            
            __fpurge(stdin);
            getchar();
            break;
        case DIVIDE:
            printf("\n\t%d / %d = %d\nEnter to continue", 
            calculator_operand1, 
            calculator_operand2,
            divide(calculator_operand1, calculator_operand2));
            
            __fpurge(stdin);
            getchar();
            break;
         case POWER:
            printf("\n\t%d ^ %d = %d\nEnter to continue", 
            calculator_operand1, 
            calculator_operand2,
            power(calculator_operand1, calculator_operand2));
            
            __fpurge(stdin);
            getchar();
            break;
         case SQUARE_ROOT:
            printf("\n\tsqrt(%d) = %d\nEnter to continue", 
            calculator_operand1, 
            squareroot(calculator_operand1));
            
            __fpurge(stdin);
            getchar();
            break; 
         case FACTORIAL:
            printf("\n\t%d! = %d\nEnter to continue", 
            calculator_operand1, 
            factorial(calculator_operand1));
            
            __fpurge(stdin);
            getchar();
            break;
          case INVERSE:
            printf("\n\t1 / %d = %d\nEnter to continue", 
            calculator_operand1, 
            inverse(calculator_operand1));
            
            __fpurge(stdin);
            getchar();
            break;
        case CURRENCY:
            printf("\n\t%d US Dolars = %d Indian Rupees\nEnter to continue", 
            calculator_operand1, 
            currency(calculator_operand1));
            
            __fpurge(stdin);
            getchar();
            break;
        case LENGTH:
            printf("\n\t%d Feet = %d Inches\nEnter to continue", 
            calculator_operand1, 
            length(calculator_operand1));
            
            __fpurge(stdin);
            getchar();
            break;
      case 11:
            exit(0);
            break;
        default:
            printf("\n\t---It should never come here---\n");
    }
}

int valid_operation(int operation)
{
    /* Check if the operation is a valid operation */
    return ((ADD <= operation) && (EXIT >= operation)) ? VALID: INVALID;
}
