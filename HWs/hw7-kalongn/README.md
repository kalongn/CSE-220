# CSE220_HW7

MIPS Programming  

Test cases for each part  

## Part A  Printing Shape 
Triangle_Test_Case_1:
```
Input:
0 (triangle)
3 (size)

Output:
*
**
***
```
Triangle_Test_Case_2:
```
Input:
0 (triangle)
6 (size)

Output:
*
**
***
****
*****
******
```

Triangle_Test_Case_3:
```
Input:
0 (triangle)
0 (size)

Output:

```
Triangle_Test_Case_4:
```
Input:
0 (triangle)
-1 (size)

Output:
Provided input is not a valid row.
```

Square_Test_Case_1:
```
Input:
1 (square)
3 (size)

Output:
***
***
***
```
Square_Test_Case_2:
```
Input:
1 (square)
6 (size)

Output:
******
******
******
******
******
******
```
Square_Test_Case_3:
```
Input:
1 (square)
0 (size)

Output:

```
Square_Test_Case_4:
```
Input:
1 (square)
-1 (size)

output:
Provided input is not a valid row.
```

Pyramid_Test_Case_1:
```
Input:
2 (pyramid)
3 (size)

Output:
  * 
 * * 
* * * 
```

Pyramid_Test_Case_2:
```
Input:
2 (pyramid)
6 (size)

Output:
     * 
    * * 
   * * * 
  * * * * 
 * * * * * 
* * * * * * 
```

Pyramid_Test_Case_3:
```
Input:
2 (pyramid)
0 (size)

Output:

```

Pyramid_Test_Case_4:
```
Input:
2 (pyramid)
-1 (size)

Output:
Provided input is not a valid row.
```

Not_a_valiod_shape_option:
```
Input:
3 (No a Shape)

Output:
Provided input is not a valid shape input.
```
## Part B Array Swap   
Valid_n_Test_Case_1:
```
pre-modification:
.data make n to 10

Input:
A[1]=1
B[1]=2
A[2]=3
B[2]=4
A[3]=5
B[3]=6
A[4]=7
B[4]=8
A[5]=9
B[5]=10
A[6]=11
B[6]=12
A[7]=13
B[7]=14
A[8]=15
B[8]=16
A[9]=17
B[9]=18
A[10]=19
B[10]=20

Output:
2 1|4 3|6 5|8 7|10 9|12 11|14 13|16 15|18 17|20 19|
```
Valid_n_Test_Case_2:
```
pre-modification:
.data make n to 1

Input:
A[1]=1
B[1]=2

Output:
2 1|
```
Valid_n_Test_Case_3:
```
pre-modification:
.data make n to 3

Input:
A[1]=1
B[1]=3
A[2]=5
B[2]=7
A[3]=9
B[3]=11

Output:
3 1|7 5|11 9|
```
Valid_n_Test_Case_4:
```
pre-modification:
.data make n to 5

Input:
A[1]=1
B[1]=2
A[2]=3
B[2]=4
A[3]=5
B[3]=6
A[4]=7
B[4]=8
A[5]=9
B[5]=10

Output:
2 1|4 3|6 5|8 7|10 9|
```
Valid_n_Test_Case_5:
```
pre-modification:
.data make n to 100

Input:
A[1]=1
B[1]=2
...
A[100]=199
B[100]=200

Output:
2 1|4 3|6 5|8 7|10 9|12 11|14 13|16 15|18 17|20 19|22 21|24 23|26 25|28 27|30 29|32 31|34 33|36 35|38 37|40 39|42 41|44 43|46 45|48 47|50 49|52 51|54 53|56 55|58 57|60 59|62 61|64 63|66 65|68 67|70 69|72 71|74 73|76 75|78 77|80 79|82 81|84 83|86 85|88 87|90 89|92 91|94 93|96 95|98 97|100 99|102 101|104 103|106 105|108 107|110 109|112 111|114 113|116 115|118 117|120 119|122 121|124 123|126 125|128 127|130 129|132 131|134 133|136 135|138 137|140 139|142 141|144 143|146 145|148 147|150 149|152 151|154 153|156 155|158 157|160 159|162 161|164 163|166 165|168 167|170 169|172 171|174 173|176 175|178 177|180 179|182 181|184 183|186 185|188 187|190 189|192 191|194 193|196 195|198 197|200 199|
```
Valid_n_Test_Case_6:
```
pre-modification:
.data make n to 10

Input:
A[1]=2
B[1]=1
A[2]=4
B[2]=3
A[3]=6
B[3]=5
A[4]=8
B[4]=7
A[5]=10
B[5]=9
A[6]=12
B[6]=11
A[7]=14
B[7]=13
A[8]=16
B[8]=15
A[9]=18
B[9]=17
A[10]=20
B[10]=19

Output:
1 2|3 4|5 6|7 8|9 10|11 12|13 14|15 16|17 18|19 20|
```
Valid_n_Test_Case_7:
```
pre-modification:
.data make n to 2

Input:
A[1]=9
B[1]=1
A[2]=3
B[2]=7

Output:
1 9|7 3|
```
Valid_n_Test_Case_8:
```
pre-modification:
.data make n to 4

Input:
A[1]=1
B[1]=1
A[2]=1
B[2]=0
A[3]=1
B[3]=1
A[4]=0
B[4]=0

Output:
1 1|0 1|1 1|0 0|
```
Invalid_n_Test_Case_1:
```
pre-modification:
.data make n to 0

Output:
n is not a valid dimension
```
Invalid_n_Test_Case_2:
```
pre-modification:
.data make n to 401

Output:
n is not a valid dimension
```
## Part C Matrix Vector Multiplication
```
Overall Style
Input:
Matrix Element First

Vector Element Second 

Output:
Vector_Output in 1xm form (instead of mx1 term for clairty)
```
Valid_Test_Case_1:
```
pre-modification:
col_m: 2, row_m: 2, col_v: 1, row_v: 2

Input:
Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4

Enter Element 1= 1
Enter Element 2= 2

Output:
[ 5 11 ]
```
Valid_Test_Case_2:
```
pre-modification:
col_m: 2, row_m: 3, col_v: 1, row_v: 2

Input:
Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4
Enter Element 5= 5
Enter Element 6= 6

Enter Element 1= 1
Enter Element 2= 2

Output:
[ 5 11 17 ]
```
Valid_Test_Case_3:
```
pre-modification:
col_m: 3, row_m: 5, col_v: 1, row_v: 3

Input:
Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4
Enter Element 5= 5
Enter Element 6= 6
Enter Element 7= 7
Enter Element 8= 8
Enter Element 9= 9
Enter Element 10= 10
Enter Element 11= 11
Enter Element 12= 12
Enter Element 13= 13
Enter Element 14= 14
Enter Element 15= 15

Enter Element 1= 16
Enter Element 2= 17
Enter Element 3= 18

Output:
[ 104 257 410 563 716 ]
```
Valid_Test_Case_4:
```
pre-modification:
col_m: 5, row_m: 5, col_v: 1, row_v: 5

Input:
Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4
Enter Element 5= 5
Enter Element 6= 6
Enter Element 7= 7
Enter Element 8= 8
Enter Element 9= 9
Enter Element 10= 10
Enter Element 11= 11
Enter Element 12= 12
Enter Element 13= 13
Enter Element 14= 14
Enter Element 15= 15
Enter Element 16= 16
Enter Element 17= 17
Enter Element 18= 18
Enter Element 19= 19
Enter Element 20= 20
Enter Element 21= 21
Enter Element 22= 22
Enter Element 23= 23
Enter Element 24= 24
Enter Element 25= 25

Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4
Enter Element 5= 5

Output:
[ 55 130 205 280 355 ]
```
Valid_Test_Case_5:
```
pre-modification:
col_m: 2, row_m: 2, col_v: 1, row_v: 2

Input:
Enter Element 1= 1
Enter Element 2= 0
Enter Element 3= 0
Enter Element 4= 1

Enter Element 1= 220
Enter Element 2= 320

Output:
[ 220 320 ]
```
Valid_Test_Case_6:
```
pre-modification:
col_m: 3, row_m: 3, col_v: 1, row_v: 3

Input:
Enter Element 1= -1
Enter Element 2= 0
Enter Element 3= 0
Enter Element 4= 0
Enter Element 5= -1
Enter Element 6= 0
Enter Element 7= 0
Enter Element 8= 0
Enter Element 9= -1

Enter Element 1= 100
Enter Element 2= 200
Enter Element 3= 300

Output:
[ -100 -200 -300 ]
```
Valid_Test_Case_7:
```
pre-modification:
col_m: 2, row_m: 3, col_v: 1, row_v: 2

Input:
Enter Element 1= -1
Enter Element 2= -2
Enter Element 3= 3
Enter Element 4= 4
Enter Element 5= -5
Enter Element 6= -6

Enter Element 1= 1
Enter Element 2= 2

Output:
[ -5 11 -17 ]
```
Valid_Test_Case_8:
```
pre-modification:
col_m: 20, row_m: 1, col_v: 1, row_v: 20

Input:

Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4
Enter Element 5= 5
Enter Element 6= 6
Enter Element 7= 7
Enter Element 8= 8
Enter Element 9= 9
Enter Element 10= 10
Enter Element 11= 11
Enter Element 12= 12
Enter Element 13= 13
Enter Element 14= 14
Enter Element 15= 15
Enter Element 16= 16
Enter Element 17= 17
Enter Element 18= 18
Enter Element 19= 19
Enter Element 20= 0

Enter Element 1= 0
Enter Element 2= 19
Enter Element 3= 18
Enter Element 4= 17
Enter Element 5= 16
Enter Element 6= 15
Enter Element 7= 14
Enter Element 8= 13
Enter Element 9= 12
Enter Element 10= 11
Enter Element 11= 10
Enter Element 12= 9
Enter Element 13= 8
Enter Element 14= 7
Enter Element 15= 6
Enter Element 16= 5
Enter Element 17= 4
Enter Element 18= 3
Enter Element 19= 2
Enter Element 20= 1

Output:
[ 1500 ]
```
Inbalid_Test_Case_1:
```
pre-modification:
col_m: 3, row_m: 3, col_v: 1, row_v: 2

Input:
Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4
Enter Element 5= 5
Enter Element 6= 6
Enter Element 7= 7
Enter Element 8= 8
Enter Element 9= 9

Enter Element 1= 1
Enter Element 2= 2

Output:
NOT WORKABLE BECAUSE OF THE DIMENSIONS
```
Invalid_Test_Case_2:
```
pre-modification:
col_m: 11, row_m: 10, col_v: 1, row_v: 11

Input:

Output:
NOT WORKABLE BECAUSE OF THE MEMORY
```
Invalid_Test_Case_3:
```
pre-modification:
col_m: 5, row_m: 5, col_v: 1, row_v: 101

Input:
Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4
Enter Element 5= 5
Enter Element 6= 6
Enter Element 7= 7
Enter Element 8= 8
Enter Element 9= 9
Enter Element 10= 10
Enter Element 11= 11
Enter Element 12= 12
Enter Element 13= 13
Enter Element 14= 14
Enter Element 15= 15
Enter Element 16= 16
Enter Element 17= 17
Enter Element 18= 18
Enter Element 19= 19
Enter Element 20= 20
Enter Element 21= 21
Enter Element 22= 22
Enter Element 23= 23
Enter Element 24= 24
Enter Element 25= 25

Output:
NOT WORKABLE BECAUSE OF THE MEMORY
```
Invalid_Test_Case_4:
```
pre-modification:
col_m: 101, row_m: 1, col_v: 1, row_v: 101

Input:

Output:
NOT WORKABLE BECAUSE OF THE MEMORY
```
Invalid_Test_Case_5:
```
pre-modification:
col_m: -10, row_m: -10, col_v: 1, row_v: 10

Input:

Output:
NOT WORKABLE BECAUSE OF THE DIMENSIONS
```

Invalid_Test_Case_6:
```
pre-modification:
col_m: 2, row_m: 2, col_v: 1, row_v: -5

Input:
Enter Element 1= 1
Enter Element 2= 2
Enter Element 3= 3
Enter Element 4= 4

Output:
NOT WORKABLE BECAUSE OF THE DIMENSIONS
```
