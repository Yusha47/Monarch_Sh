#include <stdio.h>
#include <string.h>

int isSeparator(char c)
{
    if (c == ';' || c == ',' || c == '\'')
        return 1;
    return 0;
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '>' || c == '<' || c == '!' || c == '=')
        return 1;
    return 0;
}

int isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int isParenthesis(char c)
{
    if (c == ')' || c == '(' || c == '}' || c == '{')
        return 1;
    return 0;
}

int isSeparatorString(char *c)
{
    if (strlen(c) == 1 && isSeparator(c[0]))
        return 1;
    return 0;
}

int isKeyword(char *c)
{
    if (strlen(c) == 3 && c[0] == 'i' && c[1] == 'n' && c[2] == 't')
        return 1;
    if (strlen(c) == 5 && c[0] == 'f' && c[1] == 'l' && c[2] == 'o' && c[3] == 'a' && c[4] == 't')
        return 1;
    if (strlen(c) == 4 && c[0] == 'c' && c[1] == 'h' && c[2] == 'a' && c[3] == 'r')
        return 1;
    if (strlen(c) == 4 && c[0] == 'e' && c[1] == 'l' && c[2] == 's' && c[3] == 'e')
        return 1;
    if (strlen(c) == 2 && c[0] == 'i' && c[1] == 'f')
        return 1;
    return 0;
}

int isOperatorString(char *c)
{
    if (strlen(c) > 2)
        return 0;
    if (strlen(c) == 1)
    {
        if (isOperator(c[0]))
            return 1;
        return 0;
    }
    if (isOperator(c[0]) && c[1] == '=')
        return 1;
    return 0;
}

int isParenthesisString(char *c)
{
    if (strlen(c) == 1 && isParenthesis(c[0]))
        return 1;
    return 0;
}

int isNumber(char *lex)
{
    int i, l, s;
    i = 0;
    if (isDigit(lex[i]))
    {
        s = 1;
        i++;
    }
    else if (lex[i] == '.')
    {
        s = 2;
        i++;
    }
    else
        s = 0;
    l = strlen(lex);
    if (s == 1)
        for (; i < l; i++)
        {
            if (isDigit(lex[i]))
                s = 1;
            else if (lex[i] == '.')
            {
                s = 2;
                i++;
                break;
            }
            else
            {
                s = 0;
                break;
            }
        }
    if (s == 2)
        if (isDigit(lex[i]))
        {
            s = 3;
            i++;
        }
        else
            s = 0;
    if (s == 3)
        for (; i < l; i++)
        {
            if (isDigit(lex[i]))
                s = 3;
            else
            {
                s = 0;
                break;
            }
        }
    if (s == 3)
        s = 1;
    return s;
}

int isIdentifier(char *c)
{
    int i = 0;
    int x = 0;
    for (i = 0; i < strlen(c); i++)
    {
        if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z') || c[i] == '_')
        {

            x = 1;
            continue;
        }
        else if (isDigit(c[i]) == 1)
        {
            if (x == 0)
                return 0;
        }
        else
            return 0;
    }
    return 1;
}

int main()
{
    char input[1000];
    char modified[1000];
    FILE *filePointer = freopen("F:\\GIT\\input.txt", "r", stdin);
    freopen("F:\\GIT\\output.txt", "w", stdout);

    if (filePointer == NULL)
    {
        printf("No such file.");
        return 0;
    }

    int i = 0;
    while (fscanf(filePointer, "%c", &input[i]) != EOF)
    {
        i++;
    }
    puts(input);

    input[i] = '\0';
    int flag = 0;
    int length = strlen(input), j = 0;
    int separatorOn = 0;
    for (i = 0; i < length; i++)
    {
        if (isSeparator(input[i]) == 1)
        {
            if (input[i] == '\'')
            {
                if (separatorOn)
                {
                    separatorOn = 0;
                    modified[j++] = ' ';
                    modified[j++] = input[i];
                }
                else
                {
                    modified[j++] = input[i];
                    modified[j++] = ' ';
                    separatorOn = 1;
                }
            }
            else
            {
                modified[j++] = ' ';
                modified[j++] = input[i];
            }
        }
        else if (isOperator(input[i]) == 1)
        {
            if (input[i + 1] == '=')
            {
                modified[j++] = ' ';
                modified[j++] = input[i];
                modified[j++] = input[i + 1];
                i++;
                modified[j++] = ' ';
            }
            else
            {
                modified[j++] = ' ';
                modified[j++] = input[i];
                modified[j++] = ' ';
            }
            flag = 1;
        }
        else if (isDigit(input[i]) == 1)
        {
            if (flag == 0)
            {
                flag = 1;
                modified[j++] = ' ';
            }
            modified[j++] = input[i];
        }
        else if (isParenthesis(input[i]) == 1)
        {
            modified[j++] = ' ';
            modified[j++] = input[i];
            if (input[i] != ')' && input[i] != '}')
                modified[j++] = ' ';
        }

        else
        {
            flag = 1;
            modified[j++] = input[i];
        }
    }
    modified[j] = '\0';
    printf("\n\n");
    puts(modified);
    printf("\n\n");

    input[0] = '\0';
    j = 0;
    for (i = 0; i < strlen(modified); i++)
    {
        if (modified[i] == ' ')
        {
            input[j++] = '\0';
            if (strlen(input) == 0)
            {
                j = 0;
                continue;
            }
            if (isSeparatorString(input) == 1)
            {
                printf("[sep %s] ", input);
            }
            else if (isKeyword(input) == 1)
            {
                printf("[kw %s] ", input);
            }
            else if (isIdentifier(input) == 1)
            {
                printf("[id %s] ", input);
            }
            else if (isOperatorString(input) == 1)
            {
                printf("[op %s] ", input);
            }
            else if (isParenthesisString(input) == 1)
            {
                printf("[par %s] ", input);
            }
            else if (isNumber(input) == 1)
            {
                printf("[num %s] ", input);
            }
            else
            {
                printf("[unkn %s] ", input);
            }
            j = 0;
        }
        else
        {
            input[j++] = modified[i];
        }
    }
    input[j++] = '\0';
    if (strlen(input) > 0)
    {
        if (isSeparatorString(input) == 1)
        {
            printf("[sep %s] ", input);
        }
        else if (isKeyword(input) == 1)
        {
            printf("[kw %s] ", input);
        }
        else if (isIdentifier(input) == 1)
        {
            printf("[id %s] ", input);
        }
        else if (isOperatorString(input) == 1)
        {
            printf("[op %s] ", input);
        }
        else if (isParenthesisString(input) == 1)
        {
            printf("[par %s] ", input);
        }
        else if (isNumber(input) == 1)
        {
            printf("[num %s] ", input);
        }
        else
        {
            printf("[unkn %s] ", input);
        }
    }
}
