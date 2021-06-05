# Description
This is my first assignment in College.
The language using is C language.

# Brief description / purpose
A fast food restaurant,OZJ Restaurant needs to efficiently bill customers and keep records of the
different types of foods used up.

I have been hired to develop a simple Fast Food Order & Billing System that
will enable the restaurant to bill their customers quickly, and at the end of the day
produce a Daily Sales Report.

The restaurant sells 4 types of Combo meals consisting of different combinations of
food products with prices as shown in the table below:

| COMBO |                  Food Description                 | Price (RM) |
|:-----:|:-------------------------------------------------:|:----------:|
|   A   |      2pc Fried Chicken + Coke + French Fries      |    10.00   |
|   B   |     Chicken/Beer Burger + Coke + French Fries     |    15.00   |
|   C   |     Double Cheese Burger + Coke + French Fries    |    18.00   |
|   D   | Spaghetti with Chicken Chop + Coke + French Fries |    24.00   |

For example, a customer who orders 3 sets of Combo C will be charged 3 x RM 18.00 = RM 54.00. 
He will also need to pay an extra 10% for SST (Sales / Service Tax).
So the total he need to pay is RM 59.40.

After the last customer for the day, a Daily Sales Report will be produced, showing the summary of the sales for that day.

### <ins>Method of Solution</ins>
**Structure Chart**

<div style="margin: auto;width: 50%;border: 3px solid green;padding: 10px;"><img src="/pic/structure.jpeg" height="400"></div>

**Flow Charts**

<img src="/pic/flow1.jpeg">
<img src="/pic/flow2.jpeg">
<img src="/pic/flow3.jpeg">
<img src="/pic/flow4.jpeg">

### <ins>Added features</ins>
The feature that i added is display the error when the customer pays the amount smaller than total that need to pay.

The reason for adding this feature is to remind the customer are paying the wrong amount of payment that cannot done the payment.So the customer can confirm the amount needed to pay again.

### <ins>Program Testing & Outputs</ins>
<br>Run senario 1: More than 1 customer - same combo ordered twice by same customer

|       | Inputs           |               |            | Expected Results / Outputs                                                                                                                   |               |                |                    |
|-------|------------------|---------------|------------|----------------------------------------------------------------------------------------------------------------------------------------------|---------------|----------------|--------------------|
| Cust# | Combo<br>ordered | Qty           | Payment    | Combo Charges                                                                                                                                | SST<br>(10%)  | Total charges  | Change to be given |
| 1     | C<br>A<br>C      | 10<br>2<br>10 | <br>500.00 | 18 * 10 = 180<br>10 * 2  = 20<br>18 * 10 = 180<br>Total   = 380                                                                              | <br>38.00     | <br>418.00     | <br>82.00          |
| 2     | C<br>B           | 5<br>5        | <br>200.00 | 18 * 5 = 90<br>15 * 5 = 75<br>Total  = 165                                                                                                   | <br>16.50     | <br>181.50     | <br>18.50          |
|       |                  |               |            | Total Combo Sales:<br>A 2  * 10   = 20<br>B 5  * 15   = 75<br>C 25 * 18   = 450<br>D 0  * 24   = 0<br>------       -----<br>  32         545 | <br><br>54.50 | <br><br>599.00 |                    |

<br>
<img src="/pic/prog_output/test1_1.png">
<img src="/pic/prog_output/test1_2.png">
<img src="/pic/prog_output/test1_3.png">
<img src="/pic/prog_output/test1_4.png">

<br>Run Senario 2 : 1 customer only – order all combos, different quantities

|       | Inputs           |                  |            | Expected Results / Outputs                                                                                                   |               |                |                    |
|-------|------------------|------------------|------------|------------------------------------------------------------------------------------------------------------------------------|---------------|----------------|--------------------|
| Cust# | Combo<br>ordered | Qty              | Payment    | Combo Charges                                                                                                                | SST<br>(10%)  | Total charges  | Change to be given |
| 1     | A<br>B<br>C<br>D | 1<br>2<br>3<br>4 | <br>210.00 | 10 * 1 = 10<br>15 * 2 = 30<br>18 * 3 = 54<br>24 * 4 = 96<br>Total  = 190                                                     | <br>19.00     | <br>209.00     | <br>1.00           |
|       |                  |                  |            | Total Combo Sales:<br>A 1 * 10 = 10<br>B 2 * 15 = 30<br>C 3 * 18 = 54<br>D 4 * 24 = 96<br> ------    -----<br>  10       190 | <br><br>19.00 | <br><br>209.00 |                    |

<br>
<img src="/pic/prog_output/test2_1.png">
<img src="/pic/prog_output/test2_2.png">
<img src="/pic/prog_output/test2_3.png">

<br>Run 3 scenario : 3 Customer - Order total 90 of combo A with different payment

|       | Inputs           |     |         | Expected Results / Outputs                                                                                                                        |               |                |                    |
|-------|------------------|-----|---------|---------------------------------------------------------------------------------------------------------------------------------------------------|---------------|----------------|--------------------|
| Cust# | Combo<br>ordered | Qty | Payment | Combo Charges                                                                                                                                     | SST<br>(10%)  | Total charges  | Change to be given |
| 1     | A                | 30  | 600.00  | 10 * 30 = 300                                                                                                                                     | 30.00         | 330.00         | 270.00             |
| 2     | A                | 30  | 500.00  | 10 * 30 = 300                                                                                                                                     | 30.00         | 330.00         | 170.00             |
| 3     | A                | 30  | 400.00  | 10 * 30 = 300                                                                                                                                     | 30.00         | 330.00         | 70.00              |
|       |                  |     |         | Total Combo Sales:<br>A 90 * 10    = 900<br>B 0  * 15    = 0<br>C 0  * 18    = 0<br>D 0  * 24    = 0<br>------        -----<br>  90           900 | <br><br>90.00 | <br><br>990.00 |                    |

<br>
<img src="/pic/prog_output/test3_1.png">
<img src="/pic/prog_output/test3_2.png">
<img src="/pic/prog_output/test3_3.png">
<img src="/pic/prog_output/test3_4.png">
<img src="/pic/prog_output/test3_5.png">

### <ins>Constants & variables</ins>

```c
#define SST    0.10
#define MENUA 10.00
#define MENUB 15.00
#define MENUC 18.00
#define MENUD 24.00

int quanA, quanB, quanC, quanD; 
int counterA = 0, counterB = 0, counterC = 0, counterD = 0;
int tempA, tempB, tempC, tempD,counterAllcom;
int cusNum = 1, pay;
double comCharge, chargeSST, totalSale, sstTotal;
char orderIn, nextCus;
```

| Constants | Value | Type   | Purpose                                                 |
|-----------|-------|--------|---------------------------------------------------------|
| SST       | 0.10  | double | To  define  the  value  of  SST ( Service & Sales Tax ) |
| MENUA     | 10.00 | double | To  define  the  price  of  combo A                     |
| MENUB     | 15.00 | double | To  define  the  price  of  combo B                     |
| MENUC     | 18.00 | double | To  define  the  price  of  combo C                     |
| MENUD     | 24.00 | double | To  define  the  price  of  combo D                     |
<br>

| Variables     | Type   | Purpose                                                                    |
|---------------|--------|----------------------------------------------------------------------------|
| quanA         | int    | To store the quantity of combo A that current customer order.              |
| quanB         | int    | To store the quantity of combo B that current customer order.              |
| quanC         | int    | To store the quantity of combo C that current customer order.              |
| quanD         | int    | To store the quantity of combo D that current customer order.              |
| counterA      | int    | To store the total quantity of combo A.                                    |
| counterB      | int    | To store the total quantity of combo B.                                    |
| counterC      | int    | To store the total quantity of combo C.                                    |
| counterD      | int    | To store the total quantity of combo D.                                    |
| counterAllcom | int    | To store the total of all combo sales daily.                               |
| cusNum        | int    | To count the number of customer daily.                                     |
| pay           | int    | To store the payment of customer.                                          |
| comCharge     | double | To store the total need to pay of current customer.                        |
| chargeSST     | double | To store the total SST the customer need to pay.                           |
| sstTotal      | double | To store the total of SST that charged on all combo sales daily.           |
| totalSale     | double | To store the total sales of all combo daily.                               |
| orderIn       | char   | To store the current order of combo that customer wants.                   |
| nextCus       | char   | To store the input of casher and check is there still have customer today. |
