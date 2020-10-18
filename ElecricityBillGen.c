#include<stdio.h>

float AmountOfBill(int meterReading);
void billPerUnit(int meterReading);
float elecDuty(float amount);
float gstax(float amount);
double totalPrice(float amount, float electricityDuty, float gst);
float retrunAmount(float cash, double totalAmount);

     int main()
{
	FILE *fptr;
	FILE *fptr1;
	float meterReading = 0.0, cash = 0.0, pricePerUnit = 0.0, electricityDuty = 0.0, gst = 0.0;
	int choice = 0,  year = 0; 
	float amount = 0.0, amountReturn = 0;
	double totalAmount = 0.0;
	char meterNum[1000];
	char month[20];
	char traffic = 0;
	float meterRent = 0.0, tvl = 0.0, bCharges = 0.0;
	meterRent = 7.50;
	tvl = 35.00;
	bCharges = 8.0;
	char c[1000];
	
	printf("\n1. to pay bill");
	printf("\n2. to check your bills");
	printf("\n3. to quit");
	while(!(choice == 1 || choice == 2 || choice == 3))
	{
		printf("\n\nEnter your choice: ");	
		scanf("%d",&choice);
	}
	system("cls");
	printf("\n");
	if(choice == 1)
	{
		printf("Enter meter no: ");
		scanf("%s",meterNum);
		
		printf("Enter meter reading: ");
		scanf("%f",&meterReading);
		printf("Enter month: ");
		scanf("%s",month);
		printf("Enter year: ");
		scanf("%d",&year);
		fptr = fopen(meterNum,"w");
	 
	system("cls");	-
	printf("\n");
	
	amount = AmountOfBill(meterReading);
	electricityDuty = elecDuty(amount);
	gst = gstax(amount);
	totalAmount = totalPrice(amount, electricityDuty, gst);

	printf("************************************************************************\n\n");
	printf("\n\nMeter Number:\t\t\t\t%s",meterNum);
	printf("\nMeter Reading:\t\t\t\t%.2f",meterReading);
	printf("\nMonth:\t\t\t\t\t%s",month);
	printf("\nyear:\t\t\t\t\t%d\n",year);
	printf("*****************************************************************\n\n");
	printf("Your bill for %s %d is: \t\t%.2f PKR",month, year ,amount);                     
	billPerUnit(meterReading);
	printf("\nElectricity Duty: \t\t\t%.2f",electricityDuty);
	printf("\nGeneral Sales Tax: \t\t\t%.2f",gst);
	printf("\nMeter Rent: \t\t\t\t%.2f",meterRent);
	printf("\nBank Charges: \t\t\t\t%.2f",bCharges);

	printf("\n\n*****************************************************************");
	
	printf("\n\nYour total payable bill amount is : \t\t%.2lf PKR",totalAmount);
	
	printf("\n\n*****************************************************************");
	
	fprintf(fptr,"*****************************************************************\n\n");
	fprintf(fptr,"\n\nMeter Number:\t\t\t\t%s",meterNum);
	fprintf(fptr,"\nMeter Reading:\t\t\t\t%.2f",meterReading);
	fprintf(fptr,"\nMonth:\t\t\t\t\t\t%s",month);
	fprintf(fptr,"\nyear:\t\t\t\t\t\t%d\n",year);
	fprintf(fptr,"*****************************************************************\n\n");
	fprintf(fptr,"Your bill for %s %d is: \t%.2f PKR",month, year ,amount);                     
	fprintf(fptr,"\nElectricity Duty: \t\t\t%.2f",electricityDuty);
	fprintf(fptr,"\nGeneral Sales Tax: \t\t\t%.2f",gst);
	fprintf(fptr,"\nMeter Rent: \t\t\t\t%.2f",meterRent);
	fprintf(fptr,"\nBank Charges: \t\t\t\t%.2f",bCharges);
      	
	
	fprintf(fptr,"\n\n*****************************************************************");
	
	fprintf(fptr,"\n\nYour total payable bill amount is : \t\t%.2lf PKR",totalAmount);
	
	fprintf(fptr,"\n\n*****************************************************************");
	while(!(cash >= totalAmount))
	{
		printf("\n\n\nplease pay bill amount: ");
		scanf("%f", &cash);
	}
	amountReturn = retrunAmount(cash, totalAmount);
	printf("\nYour Give: \t\t\t\t%.2f PKR ",cash);
	printf("\nYour change: \t\t\t\t%.2f PKR",amountReturn);
	printf("\n\n*****************************************************************");
	
	fprintf(fptr,"\nYour Give: \t\t\t\t%.2f PKR ",cash);
	fprintf(fptr,"\nYour change: \t\t\t\t%.2f PKR",amountReturn);
	fprintf(fptr,"\n\n*****************************************************************");
	}
	else if(choice == 2)
	{
		printf("Enter meter no: ");
		scanf("%s",meterNum);
		fptr = fopen(meterNum,"r");
		if ( (fptr = fopen(meterNum,"r")) == NULL) 
		{ 
			printf("\nBill Fill is not paid\n");  
			return 0;
		} 
		else if ((fptr = fopen(meterNum,"r")) != NULL) 
		{ 
				while(!feof(fptr))
				{
					fgets(c,1000, fptr);
					printf("%s",c);
				}
			return 0;
		}  
		
	}
	else if(choice == 3)
	{
		return 0;
	}
	fclose(fptr);
	return 0;
}
float AmountOfBill(int meterReading)
{
	float  amount = 0, amount1 = 0, amount2 = 0, amount3 = 0;

	if(meterReading <= 100)
	{

		amount = meterReading * 8.11;
	}
	else if(meterReading > 100 && meterReading <= 200)
	{
		amount1 = 100 * 8.11;
		amount2 = meterReading > 100 * 10.20;
	}
	else if(meterReading > 200 && meterReading <= 300)
	{
		amount1 = 200 * 10.20;
		amount = meterReading > 200 * 15.25;
	}
	
	else if (meterReading > 300)
	{
	     amount = meterReading * 18.00;
	}	
	
	
	return amount;	
}	
void billPerUnit(int meterReading)
{
	
	if(meterReading <= 100)
	{
		printf("\nPrice per unit you have payed is:\t ");
		printf("0 - 100 units = 8.11");		
	}
	else if(meterReading > 100 && meterReading <= 200)
	{
		printf("\nPrice per unit you have payed is :\t ");
		printf("0 - 100 units = 8.11 \n 100 - 200 units = 10.20");
	}
	else if(meterReading > 200 && meterReading <= 300)
	{
		printf("\nPrice per unit you have payed is:\t ");
		printf("0 - 200 units = 10.20 \n 200 - 300 units = 15.25");
	}
	
	else if(meterReading > 300)
	{
		printf("\nPrice per unit you have payed is:\t ");
		printf("0 - meterReading units = 18.00");
		
	}
	
}		
float elecDuty(float amount)
{
	float electricityDuty = 0.0;
	electricityDuty = (amount * 1.50) / 100;
	
	return electricityDuty;
}	
float gstax(float amount)
{	
	float gst = 0.0;
	gst = (amount * 17) / 100;
	
	return gst;
}	
double totalPrice(float amount, float electricityDuty, float gst)
{
	
	double totalAmount = 0;
	float meterRent = 0.0, tvl = 0.0, bCharges = 0.0;
	meterRent = 7.50;
	tvl = 35.00;
	bCharges = 8.0;
	
	totalAmount = amount + meterRent + electricityDuty + gst + tvl + bCharges;
	
	return totalAmount;
}
float retrunAmount(float cash, double totalAmount)
{
	float amountReturn = 0.0;
		amountReturn = cash - totalAmount;
	return amountReturn;
} 
