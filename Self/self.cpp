#include <stdio.h>
const char progdata[]="#include <stdio.h>\n"
"const char progdata[]=@@;\n"
"void quote(int lb, int ub, int incr)\n"
"{\n"
"int i;\n"
"printf(\"\\\"\");\n"
"for (i=lb; i!=ub; i=i+incr) {\n"
"if (progdata[i] == '\"')\n"
"printf(\"\\\\\\\"\");\n"
"else if (progdata[i] == '\\\\')\n"
"printf(\"\\\\\\\\\");\n"
"else if (progdata[i] == '\\n' && incr==1)\n"
"printf(\"\\\\n\\\"\\n\\\"\");\n"
"else if (progdata[i] == '\\n' && incr==-1)\n"
"printf(\"\\\"\\n\\\"n\\\\\");\n"
"else\n"
"printf(\"%c\", progdata[i]);\n"
"}\n"
"printf(\"\\\"\");\n"
"}\n"
"int main(void)\n"
"{\n"
"int i, n, lb, ub, incr;\n"
"int length = sizeof(progdata)/sizeof(progdata[0]);\n"
"scanf (\"%d\", &n);\n"
"if (n > 0) {\n"
"lb = 0;\n"
"ub = length-1;\n"
"incr = 1;\n"
"}\n"
"else {\n"
"lb = length-2;\n"
"ub = -1;\n"
"incr = -1;\n"
"}\n"
"while (n != 0) {\n"
"for (i=lb; i!=ub; i=i+incr) {\n"
"if (progdata[i] == '@' && progdata[i+incr] == '@')\n"
"{\n"
"quote(lb, ub, incr);\n"
"i=i+incr;\n"
"} else\n"
"printf(\"%c\", progdata[i]);\n"
"}\n"
"n=n-incr;\n"
"}\n"
"return 0;\n"
"}";
void quote(int lb, int ub, int incr)
{
int i;
printf("\"");
for (i=lb; i!=ub; i=i+incr) {
if (progdata[i] == '"')
printf("\\\"");
else if (progdata[i] == '\\')
printf("\\\\");
else if (progdata[i] == '\n' && incr==1)
printf("\\n\"\n\"");
else if (progdata[i] == '\n' && incr==-1)
printf("\"\n\"n\\");
else
printf("%c", progdata[i]);
}
printf("\"");
}
int main(void)
{
int i, n, lb, ub, incr;
int length = sizeof(progdata)/sizeof(progdata[0]);
scanf ("%d", &n);
if (n > 0) {
lb = 0;
ub = length-1;
incr = 1;
}
else {
lb = length-2;
ub = -1;
incr = -1;
}
while (n != 0) {
for (i=lb; i!=ub; i=i+incr) {
if (progdata[i] == '@' && progdata[i+incr] == '@')
{
quote(lb, ub, incr);
i=i+incr;
} else
printf("%c", progdata[i]);
}
n=n-incr;
}
return 0;
}