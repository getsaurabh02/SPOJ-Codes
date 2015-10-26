//#include <stdio.h>
//const char progdata[]="\0#include <stdio.h>\n"
//"const char progdata[]=@@;\n"
//"void quote(int lb, int ub, int incr)\n"
//"{\n"
//"int i;\n"
//"printf(\"\\\"\\\\0\");\n"
//"for (i=lb; progdata[i]; i=i+incr) {\n"
//"if (progdata[i] == '\"')\n"
//"printf(\"\\\\\\\"\");\n"
//"else if (progdata[i] == '\\\\')\n"
//"printf(\"\\\\\\\\\");\n"
//"else if (progdata[i] == '\\n')\n"
//"printf(\"\\\\n\\\"\\n\\\"\");\n"
//"else\n"
//"printf(\"%c\", progdata[i]);\n"
//"}\n"
//"printf(\"\\\"\");\n"
//"}\n"
//"int main(void)\n"
//"{\n"
//"int i, n, lb, ub, incr;\n"
//"int length = sizeof(progdata)/sizeof(progdata[0]);\n"
//"scanf (\"%d\", &n);\n"
//"if (n > 0) {\n"
//"lb = 1;\n"
//"ub = length;\n"
//"incr = 1;\n"
//"}\n"
//"else {\n"
//"lb = length-2;\n"
//"ub = 0;\n"
//"incr = -1;\n"
//"}\n"
//"while (n != 0) {\n"
//"for (i=lb; progdata[i]; i=i+incr) {\n"
//"if (progdata[i] == '@' && progdata[i+incr] == '@')\n"
//"{\n"
//"quote(lb, ub, incr);\n"
//"i=i+incr;\n"
//"} else\n"
//"printf(\"%c\", progdata[i]);\n"
//"}\n"
//"n--;\n"
//"}\n"
//"return 0;\n"
//"}";
//void quote(int lb, int ub, int incr)
//{
//int i;
//printf("\"\\0");
//for (i=lb; progdata[i]; i=i+incr) {
//if (progdata[i] == '"')
//printf("\\\"");
//else if (progdata[i] == '\\')
//printf("\\\\");
//else if (progdata[i] == '\n')
//printf("\\n\"\n\"");
//else
//printf("%c", progdata[i]);
//}
//printf("\"");
//}
//int main(void)
//{
//int i, n, lb, ub, incr;
//int length = sizeof(progdata)/sizeof(progdata[0]);
//scanf ("%d", &n);
//if (n > 0) {
//lb = 1;
//ub = length;
//incr = 1;
//}
//else {
//lb = length-2;
//ub = 0;
//incr = -1;
//}
//while (n != 0) {
//for (i=lb; progdata[i]; i=i+incr) {
//if (progdata[i] == '@' && progdata[i+incr] == '@')
//{
//quote(lb, ub, incr);
//i=i+incr;
//} else
//printf("%c", progdata[i]);
//}
//n--;
//}
//return 0;
//}
