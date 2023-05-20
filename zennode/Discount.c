#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>


int flat10()
{
    return 10;
}


int bulk5(int value){
    return value * .05;
    }


int bulk10(int value){
    return value * .1;
}
    


int tie50(int value){
    return value * .5;
}

int package_no(float value){
    return ceil(value);
}


void main()
{
    int price_a = 20, price_b =40, price_c =50,wrap=0; 
    int total_amount,a,b,c,item_total, no_of_packs;
    float bulk_10=0,bulk_5=0,flat_10=0,tie_50=0,pack,item_no,package, discount,final_amount;
    float total_quantity,bulk_5_a=0,bulk_5_b=0,bulk_5_c=0,tie_50_a=0,tie_50_b=0,tie_50_c=0;
    char aw[10], bw[10], cw[10];
    printf("enter the quantity of product A :  ");
    scanf("%d",&a);
    if(a>0)
    {
        printf("is it wrapped around (yes/no): ");
        scanf("%s",&aw);
    }
    printf("\nenter the quantity of product B :  ");
    scanf("%d",&b);
    if(b>0)
    {
        printf("is it wrapped around (yes/no): ");
        scanf("%s",&bw);
    }
    printf("\nenter the quantity of product C :  ");
    scanf("%d",&c);
    if(c>0)
    {
        printf("is it wrapped around (yes/no): ");
        scanf("%s",&cw);
    }
    printf("\n--               Cart details             --\n");
    printf("----------------------------------------------------------------");
    printf("\nproduct  :  quantity  :   amount");
    printf("\n      A           %d         %d", a, price_a * a);
    printf("\n      B           %d         %d", b, price_b * b);
    printf("\n      C           %d         %d", c, price_c * c);
    printf("\n----------------------------------------------------------------");
    printf("\n\n");

    total_amount=(price_a * a)+(price_b*b)+(price_c*c);
    
    printf("The total amount : %d\n\n",total_amount);
    
    //printf("\n%d",total_amount);
    
    total_quantity=a+b+c;
    
    if(total_amount>200)
    {
        flat_10=10;
    }
    if(a>10||b>10||c>10)
    {
        if(a>10)
        {
            item_total = a * price_a;
            bulk_5_a=bulk5(item_total);
        }
        if(b>10)
        {
            item_total = b * price_b;
            bulk_5_b=bulk5(item_total);
        }
        if(c>10)
        {
            item_total = c * price_c;
            bulk_5_c=bulk5(item_total);
        }
        bulk_5=bulk_5_a+bulk_5_b+bulk_5_c;
    }
    //printf("\n%d",total_amount);

    if(total_quantity>20)
    {
        bulk_10=bulk10(total_amount);
    }
    if(total_quantity>30)
    {
        if(a>15)
        {
            item_no = a-15;
            item_total = item_no * price_a;
            tie_50_a=tie50(item_total);
        }
        if(b>15)
        {
            item_no = b-15;
            item_total = item_no * price_b;
            tie_50_b=tie50(item_total);
        }
        if(c>15)
        {
            item_no = c-15;
            item_total = item_no * price_c;
            tie_50_c=tie50(item_total);
        }
        tie_50=tie_50_a+tie_50_b+tie_50_c;
    }
   
    if(flat_10>bulk_10 && flat_10>bulk_5 && flat_10>tie_50)
    {
        printf("flat_10 coupon is applied to the current order");
        printf("\n");
        discount = flat_10;
        //printf("the discount amount is %f\n", flat_10);
    }
    if(bulk_10>bulk_5 && bulk_10>flat_10 && bulk_10>tie_50)
    {
        printf("bulk_10 coupon is applied to the current order");
        printf("\n");
        discount = bulk_10;
        //printf("the discount amount is %f\n", bulk_10);
    }
    if(bulk_5>bulk_10 && bulk_5>flat_10 && bulk_5>tie_50)
    {
        printf("bulk_5 coupon is applied to the current order");
        printf("\n");
        discount = bulk_5;
        //printf("the discount amount is %f\n",bulk_5);
    }
    if(tie_50>bulk_10 && tie_50>bulk_5 && tie_50>flat_10)
    {
        printf("tiered_50 coupon is applied to the current order");
        printf("\n");
        discount = tie_50;
        //printf("the discount amount is %f\n", tie_50);
    }
    //printf("\n%d",total_amount);
    pack=total_quantity/10;
    //printf("\n%d",total_quantity);
    //printf("\n%f",pack);
    if(strcmp(aw,"yes")==0)
    {
        wrap+=a;
    }
    if(strcmp(bw,"yes")==0)
    {
        wrap+=b;
    }
    if(strcmp(cw,"yes")==0)
    {
        wrap+=c;
    }
    
    pack = total_quantity/10;
    //printf("package %f",package);
    no_of_packs = package_no(pack);
    //printf("no_of_packs  %f",no_of_packs);
    final_amount = total_amount-discount + wrap + (no_of_packs * 5);
    printf("\n");
    printf("-----------------------------------------\n");
    printf("\nCart amount :          $%d", total_amount);  // total amount
    printf("\ndiscount amount :      $%f" ,discount);  // discount amount
    printf("\npacking charge :       $%d", no_of_packs * 5);  // packing charge
    printf("\nGift Wrapping charge : $%d", wrap);  // wrapping charge
    printf("\nFinal amount :         $%f", final_amount);  // final price
    printf("\n\n-------------\n$%f\n-------------",final_amount);
}