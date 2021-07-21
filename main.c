
/**
 * Name: Celeste Amengual
 * PID: 6115500
 * Assignment: 0 (warmup)
 * Class: COP 4610
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define frand() (((double)rand()+1.)/((double)RAND_MAX+1.))

int scenarioU( int littleM, int bigM){

    int sequence;

    sequence = rand() % (bigM-littleM) + littleM;

    return sequence;

}

double scenarioV(int mean,int standardDev){

    double sequence;

    sequence = mean + standardDev * cos(2 * 3.141592 * frand()) * sqrt(-2. * log(frand()));

    return sequence;
}

double scenarioT(int mean, int standardDev, int littleM, int bigM){

    double sequence;
    double temp;
    temp = littleM - 1;

        while(temp < littleM || temp >= bigM)
            temp = round(mean + standardDev * cos(2 * 3.141592 * frand()) * sqrt(-2. * log(frand())));
        sequence = temp;

     return sequence;

}


int main () {

    time_t t;
    srand((unsigned) time(&t));

    FILE *fp;

    int k = 1; //used as a counter for formatting the creation of .csv files
    double total;

    int *s1c1Sequence = malloc(20 * sizeof(int));
    double *s1c2Sequence = malloc(20 * sizeof(double));
    double *s1c3Sequence = malloc(20 * sizeof(double));
    double *s1c4Sequence = malloc(20 * sizeof(double));
    double *s1c5Sequence = malloc(200000 * sizeof(double));

    int *s2c1Sequence = malloc(200000 * sizeof(int));
    double *s2c2Sequence = malloc(200000 * sizeof(double));
    double *s2c3Sequence = malloc(200000 * sizeof(double));
    double *s2c4Sequence = malloc(200000 * sizeof(double));
    double *s2c5Sequence = malloc(200000 * sizeof(double));

    int s3n = 2000000;
    int *s3c1Sequence = malloc(2000000 * sizeof(int));
    double *s3c2Sequence = malloc(2000000 * sizeof(double));
    double *s3c3Sequence = malloc(2000000 * sizeof(double));
    double *s3c4Sequence = malloc(2000000 * sizeof(double));
    double *s3c5Sequence = malloc(2000000 * sizeof(double));


    /**
     * Case 1 = {𝑢𝑖}
     * Case 2 = {𝑣𝑖}
     * Case 3 = {𝑡𝑖}
     * Case 4 = {𝑣𝑖/𝑡𝑖}
     * Case 5 = {4𝑢𝑖−5𝑣𝑖+2𝑡𝑖}
     */

//***************** SCENARIO 3 CASES 1-5 ***************************
    printf("\n****** SCENARIO 1 CASE 1 ******\n");

    fp = fopen("scenario1case1TEST.csv", "w");

    for (int i = 0; i < 20; i++) {

        int s1c1 = scenarioU(1, 8);

        if (k < 10) {
            fprintf(fp, "%f,", s1c1);
            k++;
        } else if (k == 10) {
            fprintf(fp, "%f\n", s1c1);
            k = 1;
        }

        s1c1Sequence[i] = s1c1;

    }
    fclose(fp);


////////////////////////////////////
    double s1c1Mean;
    double s1uSum = 0;
    for (int i = 0; i < 20; i++) {
        s1uSum = s1uSum + s1c1Sequence[i];
    }
    s1c1Mean = s1uSum / 20;
    printf("\nThe Mean of Scenario 1 Case 1 is: %f\n", s1c1Mean);

    double *subMeanS1C1 = malloc(20 * sizeof(double));

    total = 0;
    for (int i = 0; i < 20; i++) {
        subMeanS1C1[i] = pow((s1c1Sequence[i] - s1c1Mean), 2.0);
    }
    for (int i = 0; i < 20; i++) {
        total = total + subMeanS1C1[i];
    }
    double s1c1SD = sqrt(total / (20 - 1));
    printf("The Sample Standard Deviation of Scenario 1 Case 1 is: %f\n", s1c1SD);


    printf("\n****** SCENARIO 1 CASE 2 ******\n");

    fp = fopen("scenario1case2TEST.csv", "w");

    k = 0;
    for (int i = 0; i < 20; i++) {

        double s1c2 = scenarioV(5, 1);

        if (k < 10) {
            fprintf(fp, "%f,", s1c2);
            k++;
        } else if (k == 10) {
            fprintf(fp, "%f\n", s1c2);
            k = 1;
        }

        s1c2Sequence[i] = s1c2;

    }
    fclose(fp);

    //////////////////////////////////
    double s1c2Mean;
    double s1vSum = 0;
    for (int i = 0; i < 20; i++) {
        s1vSum = s1vSum + s1c2Sequence[i];
    }
    s1c2Mean = s1uSum / 20;
    printf("\nThe Mean of Scenario 1 Case 2 is: %f\n", s1c1Mean);

    double *subMeanS1C2 = malloc(20 * sizeof(double));
    total = 0;
    for (int i = 0; i < 20; i++) {
        subMeanS1C2[i] = pow((s1c2Sequence[i] - s1c2Mean), 2.0);
    }
    for (int i = 0; i < 20; i++) {
        total = total + subMeanS1C2[i];
    }
    double s1SDV = sqrt(total / (20 - 1));
    printf("The Sample Standard Deviation of Scenario 1 Case 2 is: %f\n", s1SDV);

    printf("\n****** SCENARIO 1 CASE 3 ******\n");

    fp = fopen("scenario1case3TEST.csv", "w");

    for (int i = 0; i < 20; i++) {
        double s1c3 = scenarioT(5, 1, 1, 8);


        if (k < 10) {
            fprintf(fp, "%f,", s1c3);
            k++;
        } else if (k == 10) {
            fprintf(fp, "%f\n", s1c3);
            k = 1;
        }


        s1c3Sequence[i] = s1c3;
    }
    fclose(fp);

    //////////////////////////////////
    double s1c3Mean;
    double s1c3Sum = 0;
    for (int i = 0; i < 20; i++) {
        s1c3Sum = s1c3Sum + s1c4Sequence[i];
    }
    s1c3Mean = s1c3Sum / 20;
    printf("\nThe Mean of Scenario 1 Case 3 is: %f\n", s1c3Mean);


    double *subMeanS1C3 = malloc(20 * sizeof(double));
    total = 0;
    for (int i = 0; i < 20; i++) {
        subMeanS1C3[i] = pow((s1c3Sequence[i] - s1c3Mean), 2.0);
    }
    for (int i = 0; i < 20; i++) {
        total = total + subMeanS1C3[i];
    }
    double s1c3SD = sqrt(total / (20 - 1));
    printf("The Sample Standard Deviation of Scenario 1 Case 3 is: %f\n", s1c3SD);

    printf("\n****** SCENARIO 1 CASE 4 ******\n");

    for (int i = 0; i < 20; i++) {

        double s1c4 = s1c2Sequence[i] / s1c3Sequence[i];

        if (k < 10) {
            fprintf(fp, "%f,", s1c4);
            k++;
        } else if (k == 10) {
            fprintf(fp, "%f\n", s1c4);
            k = 1;
        }

        s1c4Sequence[i] = s1c4;

    }
    /////////////////////////////////////////
    double s1c4Mean;
    double s1v_tSum = 0;
    for (int i = 0; i < 20; i++) {
        s1v_tSum = s1v_tSum + s1c4Sequence[i];
    }
    s1c3Mean = s1v_tSum / 20;
    printf("\nThe Mean of Scenario 1 Case 4 is: %f\n", s1c3Mean);


    double *subMeanS1C4 = malloc(20 * sizeof(double));
    total = 0;
    for (int i = 0; i < 20; i++) {
        subMeanS1C4[i] = pow((s1c4Sequence[i] - s1c4Mean), 2.0);
    }
    for (int i = 0; i < 20; i++) {
        total = total + subMeanS1C4[i];
    }
    double s1SDV_T = sqrt(total / (20 - 1));
    printf("The Sample Standard Deviation of Scenario 1 Case 4 is: %f\n", s1SDV_T);

    printf("\n****** SCENARIO 1 CASE 5 ******\n");

    for (int i = 0; i < 20; i++) {
        double s1c5 = (4 * s1c1Sequence[i]) - (5 * s1c2Sequence[i]) + (2 * s1c3Sequence[i]);


        if (k < 10) {
            fprintf(fp, "%f,", s1c5);
            k++;
        } else if (k == 10) {
            fprintf(fp, "%f\n", s1c5);
            k = 1;
        }

        s1c5Sequence[i] = s1c5;

    }
    //////////////////////////////////////////
    double s1c5Mean;
    double s1c5Sum = 0;
    for (int i = 0; i < 20; i++) {
        s1c5Sum = s1c5Sum + s1c5Sequence[i];
    }
    s1c5Mean = s1c5Sum / 20;
    printf("\nThe Mean of Scenario 1 Case 5 is: %f\n", s1c5Mean);


    double *subMeanS1C5 = malloc(20 * sizeof(double));
    total = 0;
    for (int i = 0; i < 20; i++) {
        subMeanS1C5[i] = pow((s1c5Sequence[i] - s1c5Mean), 2.0);
    }
    for (int i = 0; i < 20; i++) {
        total = total + subMeanS1C5[i];
    }
    double s1c5SD = sqrt(total / (20 - 1));
    printf("The Sample Standard Deviation of Scenario 1 Case 5 is: %f\n", s1c5SD);


//***************** SCENARIO 2 CASES 1-5 ***************************

    printf("\n****** SCENARIO 2 CASE 1 ******\n");

    for (int i = 0; i < 200000; i++) {
        double s2c1 = scenarioU(1, 2000);

        if (k < 10) {
            fprintf(fp, "%f,", s2c1);
            k++;
        } else if (k == 10) {
            fprintf(fp, "%f\n", s2c1);
            k = 1;
        }

        s2c1Sequence[i] = s2c1;

    }
//    ///////////////////////////////////////
    double s2c1Mean;
    double s2uSum = 0;
    for (int i = 0; i < 200000; i++) {
        s2uSum = s2uSum + s2c1Sequence[i];
    }
    s2c1Mean = s2uSum / 200000; // MEAN of Scenario 2 Case 1
    printf("\nThe Mean of Scenario 2 Case 1 is: %f\n", s2c1Mean);


    double *subMeanS2C1 = malloc(200000 * sizeof(double));
    total = 0;
    for (int i = 0; i < 200000; i++) {
        subMeanS2C1[i] = pow((s2c1Sequence[i] - s2c1Mean), 2.0);
    }
    for (int i = 0; i < 200000; i++) {
        total = total + subMeanS2C1[i];
    }
    double s2c1SD = sqrt(total / (200000 - 1)); //STANDARD DEVIATION of Scenario 2 Case 1
    printf("The Sample Standard Deviation of Scenario 2 Case 1 is: %f\n", s2c1SD);
//
    printf("\n****** SCENARIO 2 CASE 2 ******\n");

    for (int i = 0; i < 200000; i++) {
        double s2c2 = scenarioV(pow(2.0, 10.0), pow(2.0, 8.0));

        if (k < 10) {
            fprintf(fp, "%f,", s2c2);
            k++;
        } else if (k == 10) {
            fprintf(fp, "%f\n", s2c2);
            k = 1;
        }

        s2c2Sequence[i] = s2c2;

    }
    //////////////////////////////////////////
    double s2c2Mean;
    double s2vSum = 0;
    for (int i = 0; i < 200000; i++) {
        s2vSum = s2vSum + s2c2Sequence[i];
    }
    s2c2Mean = s2uSum / 200000; // MEAN of Scenario 2 Case 2
    printf("\nThe Mean of Scenario 2 Case 2 is: %f\n", s2c2Mean);


    double *subMeanS2C2 = malloc(200000 * sizeof(double));
    total = 0;
    for (int i = 0; i < 200000; i++) {
        subMeanS2C2[i] = pow((s2c2Sequence[i] - s2c2Mean), 2.0);
    }
    for (int i = 0; i < 200000; i++) {
        total = total + subMeanS2C2[i];
    }
    double s2c2SD = sqrt(total / (200000 - 1)); //STANDARD DEV of Scenario 2 Case 2
    printf("The Sample Standard Deviation of Scenario 2 Case 2 is: %f\n", s2c2SD);

    printf("\n****** SCENARIO 2 CASE 3 ******\n");

    for (int i = 0; i < 200000; i++) {
        double s2c3 = scenarioT(pow(2.0, 10.0), pow(2.0, 8.0), 1, 2000);

        if (k < 10) {
            fprintf(fp, "%f,", s2c3);
            k++;
        } else if (k == 10) {
            fprintf(fp, "%f\n", s2c3);
            k = 1;
        }

        s2c3Sequence[i] = s2c3;
    }
/////////////////////////////////////////////
        double s2c3Mean;
        double s2c3Sum = 0;
        for (int i = 0; i < 200000; i++) {
            s2c3Sum = s2c3Sum + s2c3Sequence[i];
        }
        s2c3Mean = s2c3Sum / 200000; // MEAN of Scenario 2 Case 3
        printf("\nThe Mean of Scenario 2 Case 3 is: %f\n", s2c3Mean);


        double *subMeanS2C3 = malloc(200000 * sizeof(double));
        total = 0;
        for (int i = 0; i < 200000; i++) {
            subMeanS2C3[i] = pow((s2c3Sequence[i] - s2c3Mean), 2.0);
        }
        for (int i = 0; i < 200000; i++) {
            total = total + subMeanS2C3[i];
        }
        double s2c3SD = sqrt(total / (200000 - 1)); //STANDARD DEV of Scenario 2 Case 3
        printf("The Sample Standard Deviation of Scenario 2 Case 3 is: %f\n", s2c3SD);
//
        printf("\n****** SCENARIO 2 CASE 4 ******\n");

        for (int i = 0; i < 200000; i++) {
            double s2c4 = s2c2Sequence[i] / s2c3Sequence[i];

            if (k < 10) {
                fprintf(fp, "%f,", s2c4);
                k++;
            } else if (k == 10) {
                fprintf(fp, "%f\n", s2c4);
                k = 1;
            }

            s2c4Sequence[i] = s2c4;
        }
//    //////////////////////////////////////////
        double s2c4Mean;
        double s2c4Sum = 0;
        for (int i = 0; i < 200000; i++) {
            s2c4Sum = s2c4Sum + s2c4Sequence[i];
        }
        s2c4Mean = s2uSum / 200000; // MEAN of Scenario 2 Case 3
        printf("\nThe Mean of Scenario 2 Case 4 is: %f\n", s2c4Mean);


        double *subMeanS2C4 = malloc(200000 * sizeof(double));
        total = 0;
        for (int i = 0; i < 200000; i++) {
            subMeanS2C4[i] = pow((s2c4Sequence[i] - s2c4Mean), 2.0);
        }
        for (int i = 0; i < 200000; i++) {
            total = total + subMeanS2C4[i];
        }
        double s2c4SD = sqrt(total / (200000 - 1)); //STANDARD DEV
        printf("The Sample Standard Deviation of Scenario 2 Case 4 is: %f\n", s2c4SD);

        printf("\n****** SCENARIO 2 CASE 5 ******\n");

        for (int i = 0; i < 200000; i++) {
            double s2c5 = (4 * s2c1Sequence[i]) - (5 * s2c2Sequence[i]) + (2 * s2c3Sequence[i]);

            if (k < 10) {
                fprintf(fp, "%f,", s2c5);
                k++;
            } else if (k == 10) {
                fprintf(fp, "%f\n", s2c5);
                k = 1;
            }

            s2c5Sequence[i] = s2c5;
            // printf("%f\n", sTwo452[i]);
        }
        /////////////////////////////////////////////
        double s2c5Mean;
        double s2c5Sum = 0;
        for (int i = 0; i < 200000; i++) {
            s2c5Sum = s2c5Sum + s2c5Sequence[i]; //adds up each value
        }
        s2c5Mean = s2c5Sum / 200000; // Calculates Mean of Scenario 2 Case 5
        printf("\nThe Mean of Scenario 2 Case 5 is: %f\n", s2c5Mean);

        //double subMeanTwo452[s2n];
        double *subMeanS2C5 = malloc(200000 * sizeof(double));
        total = 0;
        for (int i = 0; i < 200000; i++) {
            subMeanS2C5[i] = pow((s2c5Sequence[i] - s2c5Mean), 2.0); //Array of (x-mean)^2 for each value in sequence
        }
        for (int i = 0; i < 200000; i++) {
            total = total + subMeanS2C5[i]; // adds total (x-mean)^2
        }
        double s2c5SD = sqrt(total / (200000 - 1)); // Calculates STANDARD DEV
        printf("The Sample Standard Deviation of Scenario 2 Case 5 is: %f\n", s2c5SD);

//***************** SCENARIO 3 CASES 1-5 ***************************

        printf("\n****** SCENARIO 3 CASE 1 ******\n");

        fp = fopen("scenario3case1TEST.csv", "w");

        for (int i = 0; i < 2000000; i++) {
            double s3c1 = scenarioU(1, 8100);

            if (k < 10) {
                fprintf(fp, "%f,", s3c1);
                k++;
            } else if (k == 10) {
                fprintf(fp, "%f\n", s3c1);
                k = 1;
            }

            s3c1Sequence[i] = s3c1;

        }
        fclose(fp);

        /////////////////////////////////
        double s3c1Mean;
        double s3c1Sum = 0;
        for (int i = 0; i < 2000000; i++) {
            s3c1Sum = s3c1Sum + s3c1Sequence[i];
        }
        s3c1Mean = s3c1Sum / s3n; // MEAN of Scenario 3 Case 1
        printf("\nThe Mean of Scenario 3 Case 1 is: %f\n", s3c1Mean);

        //double subMeanU3[s3n];
        int *subMeanS3C1 = malloc(2000000 * sizeof(int));
        total = 0;
        for (int i = 0; i < 2000000; i++) {
            subMeanS3C1[i] = pow((s3c1Sequence[i] - s3c1Mean), 2.0);
        }
        for (int i = 0; i < 2000000; i++) {
            total = total + subMeanS3C1[i];
        }
        double s3c1SD = sqrt(total / (2000000 - 1)); //STANDARD DEV of Scenario 3 Case 1
        printf("The Sample Standard Deviation of Scenario 3 Case 1 is: %f\n", s3c1SD);

        printf("\n****** SCENARIO 3 CASE 2 ******\n");

        fp = fopen("scenario3case2TEST.csv", "w");

        k = 1;

        for (int i = 0; i < 2000000; i++) {
            double s3c2 = scenarioV(pow(2.0, 12.0), (1.3 * pow(2.0, 10.)));


            if (k < 10) {
                fprintf(fp, "%f,", s3c2);
                k++;
            } else if (k == 10) {
                fprintf(fp, "%f\n", s3c2);
                k = 1;
            }

            s3c2Sequence[i] = s3c2;

        }

        fclose(fp);
        /////////////////////////////////////
        double s3c2Mean;
        double s3c2Sum = 0;
        for (int i = 0; i < 2000000; i++) {
            s3c2Sum = s3c2Sum + s3c2Sequence[i];
        }
        s3c2Mean = s3c2Sum / 2000000; // MEAN of Scenario 3 Case 2
        printf("\nThe Mean of Scenario 3 Case 2 is: %f\n", s3c2Mean);

        double *subMeanS3C2 = malloc(2000000 * sizeof(double));
        total = 0;
        for (int i = 0; i < 2000000; i++) {
            subMeanS3C2[i] = pow((s3c2Sequence[i] - s3c2Mean), 2.0); // Calculates (𝑥𝑖−mean)^2 for each x value
        }
        for (int i = 0; i < 2000000; i++) {
            total = total + subMeanS3C2[i]; // Adds all (𝑥𝑖−mean)^2
        }
        double s3c2SD = sqrt(total / (2000000 - 1)); //STANDARD DEV of Scenario 3 Case 2
        printf("The Sample Standard Deviation of Scenario 3 Case 2 is: %f\n", s3c2SD);

        printf("\n****** SCENARIO 3 CASE 3 ******\n");

        fp = fopen("scenario3case3TEST.csv", "w");

        k = 1;

        for (int i = 0; i < 2000000; i++) {
            double s3c3 = scenarioT(pow(2.0, 10.0), (1.3 * pow(2.0, 10.0)), 1, 8100);


            if (k < 10) {
                fprintf(fp, "%f,", s3c3);
                k++;
            } else if (k == 10) {
                fprintf(fp, "%f\n", s3c3);
                k = 1;
            }


            s3c3Sequence[i] = s3c3;

        }

        fclose(fp);
///////////////////////////////////////
        double s3c3Mean;
        double s3c3Sum = 0;
        for (int i = 0; i < s3n; i++) {
            s3c3Sum = s3c3Sum + s3c3Sequence[i];
        }
        s3c3Mean = s3c3Sum / s3n; // MEAN of Scenario 3 Case 3 {𝑡𝑖}
        printf("\nThe Mean of Scenario 3 Case 3 is: %f\n", s3c3Mean);

        double *subMeanS3C3 = malloc(2000000 * sizeof(double));
        total = 0;
        for (int i = 0; i < s3n; i++) {
            subMeanS3C3[i] = pow((s3c3Sequence[i] - s3c3Mean), 2.0);
        }
        for (int i = 0; i < s3n; i++) {
            total = total + subMeanS3C3[i];
        }
        double s3c3SD = sqrt(total / (2000000 - 1)); //STANDARD DEV
        printf("The Sample Standard Deviation of Scenario 3 Case 3 is: %f\n", s3c3SD);


        printf("\n****** SCENARIO 3 CASE 4 ******\n");

        fp = fopen("scenario3case4TEST.csv", "w");

        k = 1;

        for (int i = 0; i < 2000000; i++) {

            double s3c4 = s3c2Sequence[i] / s3c3Sequence[i];

            if (k < 10) {
                fprintf(fp, "%f,", s3c4);
                k++;
            } else if (k == 10) {
                fprintf(fp, "%f\n", s3c4);
                k = 1;
            }

            s3c4Sequence[i] = s3c4;

        }

        fclose(fp);
        ///////////////////////////
        double s3c4Mean;
        double s3c4Sum = 0;
        for (int i = 0; i < 2000000; i++) {
            s3c4Sum = s3c4Sum + s3c4Sequence[i];
        }
        s3c4Mean = s3c4Sum / 2000000; // MEAN of Scenario 3 Case 4
        printf("\nThe Mean of Scenario 3 Case 4 is: %f\n", s3c4Mean);

        double *subMeanS3C4 = malloc(2000000 * sizeof(double));
        total = 0;
        for (int i = 0; i < 2000000; i++) {
            subMeanS3C4[i] = pow((s3c4Sequence[i] - s3c4Mean), 2.0); // Calculates (𝑥𝑖−mean)^2 for each x value
        }
        for (int i = 0; i < 2000000; i++) {
            total = total + subMeanS3C4[i]; // Adds all (𝑥𝑖−mean)^2
        }
        double s3c4SD = sqrt(total / (2000000 - 1)); //STANDARD DEV of Scenario 3 Case 4
        printf("The Sample Standard Deviation of Scenario 3 Case 4 is: %f\n", s3c4SD);

        printf("\n****** SCENARIO 3 CASE 5 ******\n");

        fp = fopen("scenario3case5TEST.csv", "w");

        k = 1;

        for (int i = 0; i < 2000000; i++) {
            double s3c5 = (4 * s3c1Sequence[i]) - (5 * s3c2Sequence[i]) + (2 * s3c3Sequence[i]);


            if (k < 10) {
                fprintf(fp, "%f,", s3c5);
                k++;
            } else if (k == 10) {
                fprintf(fp, "%f\n", s3c5);
                k = 1;
            }

            s3c5Sequence[i] = s3c5;

        }
        fclose(fp);
        /////////////////////////////
        double s3c5Mean;
        double s3c5Sum = 0;
        for (int i = 0; i < 2000000; i++) {
            s3c5Sum = s3c5Sum + s3c5Sequence[i];
        }
        s3c5Mean = s3c5Sum / 2000000; // MEAN of Scenario 3 case 5
        printf("\nThe Mean of Scenario 3 Case 5 is: %f\n", s3c5Mean);


        double *subMeanS3C5 = malloc(2000000 * sizeof(double));
        total = 0;
        for (int i = 0; i < 2000000; i++) {
            subMeanS3C5[i] = pow((s3c5Sequence[i] - s3c5Mean), 2.0);
        }
        for (int i = 0; i < 2000000; i++) {
            total = total + subMeanS3C5[i];
        }
        double s3c5SD = sqrt(total / (2000000 - 1)); //STANDARD DEV of Scenario 3 Case 5
        printf("The Sample Standard Deviation of Scenario 3 Case 5 is: %f\n", s3c5SD);

}