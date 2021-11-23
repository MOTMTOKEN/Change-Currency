#include <stdio.h>

/*  
Programmet skall läsa in priser i aktuell utländsk valuta och sedan presentera
summan av priserna i aktuell valuta och i svenska kronor. Användaren ska kunna ange växlingskurs.
*/



// deklarerar funktionerna så att datorn har sett dom innan.
float set_currency(void);
float meny(float exchangeRate);
float choice(void);                       
float converting_price(float n);
float giveprice(void);
void lastsum(float num3, float exchangeRate);



// i main ska en loop ske där programmet körs hela tiden förutom när användaren vill stänga.
int main(void)
{
    // behöver ha denna printf vid program start endast.
    printf("\nYour shopping assistant\n");                      
    float exchangeRate;
    // måste sätta exhangerate till 1 så att den har värdet 1 när programmet körs.
    exchangeRate = 1;

    int b;

    do
    {
        // sätter värdet 1 till meny.
        meny(exchangeRate);                                                 
        
        // loopar choice så den alltid kommer upp om inget annat stoppar den. Sedan sätter värdet av den till b.
        b = choice();                                                        

        if (b == 1)         // om värdet användaren skrev var 1.
        {
             // sätt exchangerate till vad man skrev i set_currency för att den ska sparas till rätt värde.
            exchangeRate = set_currency();                                           
        }
        else if (b == 2)          // om användaren hade skrivit in 2.
        {
            float c;
            // sätt c till summan man fick av converting_price.
            c = converting_price(b);                                            
            // anropar summan och exchangerate till funktionen som skriver ut det sista.
            lastsum(c, exchangeRate);                                           
        }
        else if (b == 3)      // om man hade skrivit 3.
        {
            // skriver ut end of program och loopen slutar pga av rad 47.
            printf("\nEnd of program!\n\n");                                        
        }
        else
        {
            // om man skrev något annat än 1-3.
            printf("\nNot a valid choice!\n");                                    
        }

    } while (b != 3);    // loopas så länge det inte skrivs 3.

    return 0;
}


 // funktionen tar värde 1-3 från användaren och returnerar det, den tar inga parametrar.
float choice(void)      
{
    float n;

    printf("\nGive your choice (1 - 3): ");                                    
    scanf("%f", &n);

    return n;
}

// funktionen tar värde till exhangerate från användaren och returnerar det värdet. Ingen parameter tas in.
float set_currency(void)
{
    float exchangeRate;
    printf("\nGive exchange rate of your choosing: ");                           
    scanf("%f", &exchangeRate);

    return exchangeRate;
}


// funktionen skriver ut vad exchangerate är just då. Den tar in en parameter.
float meny(float exchangeRate)
{

    printf("\n1. Set exchange rate in SEK (current rate: %.2f)\n", exchangeRate);                   
    printf("2. Convert prices from the foreign currency");                                              
    printf("\n3. End\n");

    return exchangeRate;
}

// Fukntionen skall summera alla positiva siffror man anger och returnera det. Vi har en parameter.
float converting_price(float n)
{

    float sum5 = 0;
    float num5;
    printf("\n");

    // medan man skrivit 0 eller ett högre tal.
    while (num5 >= 0)                                           
    {
         // måste få värdet först.
        num5 = giveprice();                                    
        // vi vill endast addera positiva tal.
        if (num5 >= 0)                                          
        {
            // adderar sum5 med värdet som givits.
            sum5 = sum5 + num5;                                          
        }   
        
    }
    // returnerar summan i slutet av de tal som önskades.
    return sum5;                                                   
}


// Denna funktion är den man använder för att få en float number från användare och returnerar det talet. 
// Denna funktion används för att loopas i andra funktioner. Denna funktion tar inga parametrar.
float giveprice(void)
{
    float n;
    printf("Give price (finish with an int < 0): ");              
    scanf("%f", &n);
    return n;
}

// denna funktion används för att skriva ut resultaten som vi har jobbat för i dem andra funktionerna. Den tar in två parametrar.
void lastsum(float num3, float exchangeRate)                              // får två parametrar från main där vi har summan och det exchangerate som skall användas.
{
   
   
    // skriver vi ut summan.
    printf("\nSum in foreign currency: %.2f", num3);                

    
     // skriver vi ut summan gånger vad exchangerate är just då.
    printf("\nSum in SEK: %.2f\n", num3 * exchangeRate);              
}

