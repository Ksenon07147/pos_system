#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#pragma warning (disable:4996)
#define SST 0.10
#define MENUA 10.00
#define MENUB 15.00
#define MENUC 18.00
#define MENUD 24.00
void logo(void);
void order(void);
void daily(void);

//variables
int quanA, quanB, quanC, quanD; //temporary quantity counter(reset when finish loop)
int counterA = 0, counterB = 0, counterC = 0, counterD = 0;//total quantity
int tempA, tempB, tempC, tempD, counterAllcom;
int cusNum = 1, pay;
double comCharge, chargeSST, totalSale, sstTotal;
char orderIn, nextCus;

void main()
{
	logo();
	order();

	system("pause");
}


void logo()
{
	printf("\n");
	printf("    _|_|     _|_|_|_|_|         _|  \n");
	printf("  _|    _|         _|           _|  \n");
	printf("  _|    _|       _|             _|  \n");
	printf("  _|    _|     _|         _|    _|  \n");
	printf("    _|_|     _|_|_|_|_|     _|_|    \n");
	printf("  WELCOME TO OZJ RESTAURANT!!!\n");
	printf(" So Fast, so hot.\n\n");
	printf(" \t\t\t\t\t\tDesign by Ooi Zhi Jie\n");

}


void order()
{
	do
	{
		printf(" _______________\\		MENU			/_______________\n");
		printf(" COMBO A:\n" "\t2pc Fried Chicken + Coke + french fries.[RM10.00]\n");
		printf(" COMBO B:\n" "\tChicken/Beer Burger + Coke + french fries.[RM15.00]\n");
		printf(" COMBO C:\n" "\tDouble Cheese Burger + Coke + french fries.[RM18.00]\n");
		printf(" COMBO D:\n" "\tSpaghetti with chicken chop + Coke + french fries.[RM24.00]\n");
		printf("\n Customer Number	:%d\n", cusNum);

		do
		{
			rewind(stdin);
			printf(" Please select a combo\n (Enter A, B, C, D /Enter other to finish ordering.)\t:");
			scanf(" %c", &orderIn);

			switch (orderIn)
			{
			case 'A':
			case 'a':
				printf(" Quantity	:");
				scanf("%d", &quanA);
				printf(" COMBO A %d set(s):RM%.2f\n", quanA, (quanA * MENUA));
				counterA = counterA + quanA;
				comCharge = comCharge + (quanA * MENUA);
				break;
			case 'B':
			case 'b':
				printf(" Quantity	:");
				scanf("%d", &quanB);
				printf(" COMBO B %d set(s),RM%.2f\n", quanB, (quanB * MENUB));
				counterB = counterB + quanB;
				comCharge = comCharge + (quanB * MENUB);
				break;
			case 'C':
			case 'c':
				printf(" Quantity	:");
				scanf("%d", &quanC);
				printf(" COMBO C %d set(s),RM%.2f\n", quanC, quanC * MENUC);
				counterC = counterC + quanC;
				comCharge = comCharge + quanC * MENUC;
				break;
			case 'D':
			case 'd':
				printf(" Quantity	:");
				scanf("%d", &quanD);
				printf(" COMBO D %d set(s),RM%.2f\n", quanD, quanD * MENUD);
				counterD = counterD + quanD;
				comCharge = comCharge + quanD * MENUD;
				break;
			default:
				break;
			}



		} while (orderIn == 'A' || orderIn == 'B' || orderIn == 'C' || orderIn == 'D' || orderIn == 'a' || orderIn == 'b' || orderIn == 'c' || orderIn == 'd');

		chargeSST = comCharge * SST;
		printf(" =====================================\n"
			"\tCombo Charges = RM%.2f\n"
			"\tAdd SST(10%%) = RM%.2f\n"
			"\tTOTAL TO PAY = RM%.2f\n", comCharge, chargeSST, comCharge + chargeSST);
		do
		{

			printf("\n\tAmount Paid	:RM");
			scanf("%d", &pay);
			if (pay >= (comCharge + chargeSST))
			{
				printf("\tChange Due = RM%.2f\n", pay - (comCharge + chargeSST));
			}
			else
			{
				printf("\n\tInvalid value entered, please enter the correct payment received.");
			}
		} while ((pay < (comCharge + chargeSST)));

		printf("\n Thank you for choosing our restaurant!!\n");

		printf(" Next Customer? Yes/No(Y/N) :");
		rewind(stdin);
		scanf("%c", &nextCus);

		if (nextCus == 'Y' || nextCus == 'y')
		{
			++cusNum;
			quanA = 0;
			quanB = 0;
			quanC = 0;
			quanD = 0;
			comCharge = 0;
		}
		else if (nextCus == 'N' || nextCus == 'n')
		{
			daily();
			break;
		}
	} while (nextCus != 'N' || nextCus != 'n');
}

void daily()
{
	printf(" ===============================================================\n"
		" 		Daily		Report		\n"
		" ===============================================================\n");

	totalSale = (counterA * MENUA) + (counterB * MENUB) + (counterC * MENUC) + (counterD * MENUD);
	sstTotal = totalSale * SST;
	counterAllcom = counterA + counterB + counterC + counterD;
	printf(" Total Number of Customers = %d\n\n"
		" Combo Sales For Today = %d\n"
		" Combo\t Quantity Sold\t Sales Amount\n"
		" A\t %3d\t\t RM%.2f\n"
		" B\t %3d\t\t RM%.2f\n"
		" C\t %3d\t\t RM%.2f\n"
		" D\t %3d\t\t RM%.2f\n"
		" ======\t ====\t\t =========\n"
		" TOTALS\t %3d\t\t RM %.2f\n", cusNum, counterAllcom, counterA, (counterA * MENUA), counterB, (counterB * MENUB), counterC, (counterC * MENUC), counterD, (counterD * MENUD), (counterA + counterB + counterC + counterD), totalSale);
	printf(" TOTAL SST charges\t= RM %.2f \n", sstTotal);
	printf(" TOTAL RM collected\t= RM %.2f \n", (totalSale + sstTotal));
}
