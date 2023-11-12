## Matrix Multiplication README
![sparseMatrix](https://github.com/fmunsal/Multiplying_Sparse_Matrix/assets/119849116/134ba1a2-b455-4265-9f01-c1c385ec887f)
### Overview:

This C program performs the multiplication of two sparse matrices. Initially, the matrices are defined as `sparseMatrix1` and `sparseMatrix2`. Subsequently, compact arrays of structs, named `compact_matrix_1` and `compact_matrix_2`, are created to represent only the non-zero elements. The multiplication operation is executed using a function called `multiply`, and the result is printed to the screen using the `print` function.

### Code Structure:

The code is organized into several sections:

1. **Header Files and Definitions:**
   - Necessary header files (`stdio.h` and `stdlib.h`) are included, and constants are defined for the maximum number of terms and dimensions of the matrices.

2. **Structure Definition:**
   - A structure named `non_zero_values` is defined to represent a non-zero element in a sparse matrix. This structure includes the row, column, and value of the element.

3. **Function Declarations:**
   - Function prototypes for the `print` and `multiply` functions are declared.

4. **Main Function:**
   - The `main` function initializes two input matrices (`sparseMatrix1` and `sparseMatrix2`), creates compact matrices for them, and then calls the `multiply` function to perform matrix multiplication.

5. **Matrix Multiplication Function (`multiply`):**
   - This function takes two compact matrices as input, performs matrix multiplication, converts the result to a normal matrix, creates a compact matrix for the result, and finally prints the result.

6. **Printing Function (`print`):**
   - The `print` function is responsible for printing a compact matrix.

### Example Matrices:

```c
int sparseMatrix1[_K][_L] = 
{ 
    {0, 10, 0, 5}, 
    {0, 2, 4, 0}, 
    {0, 0, 0, 0}, 
    {3, 0, 0, 7}, 
};

int sparseMatrix2[_L][_M] = 
{ 
    {1, 0, 0, 2}, 
    {0, 0, 3, 0}, 
    {0, 8, 0, 0}, 
    {5, 0, 10, 0}, 
};
```

### Result:

The result of the multiplication is displayed in a compact matrix format.

### Note:

- The code uses a compact representation for sparse matrices to save space.
- Make sure to adjust the input matrices and their dimensions according to your requirements.

This README file aims to provide a comprehensive guide on how to use the program and understand its structure. If you have any specific questions or issues, feel free to reach out for assistance.Certainly! Here is an English README for your C program:

---

## Matris Çarpımı 

### Genel Bakış:

Bu C programı, iki seyrek matrisin çarpımını gerçekleştirir. İlk olarak, matrisler `sparseMatrix1` ve `sparseMatrix2` olarak tanımlanır. Ardından, yalnızca sıfır olmayan elemanları temsil etmek üzere `compact_matrix_1` ve `compact_matrix_2` adlı kompakt struct dizi oluşturulur. Çarpma işlemi, `multiply` adlı bir fonksiyon kullanılarak gerçekleştirilir ve sonuç `print` fonksiyonu kullanılarak ekrana yazdırılır.

### Kod Yapısı:

Kod şu bölümlere ayrılmıştır:

1. **Başlık Dosyaları ve Tanımlamalar:**
   - Gerekli başlık dosyaları (`stdio.h` ve `stdlib.h`) eklenir ve matrislerin maksimum terim sayısı ile boyutları için bazı sabitler tanımlanır.

2. **Yapı Tanımı:**
   - `non_zero_values` adlı bir yapı, bir seyrek matristeki sıfır olmayan bir elemanı temsil etmek üzere tanımlanır. Bu yapı, elemanın satırını, sütununu ve değerini içerir.

3. **Fonksiyon Bildirimleri:**
   - `print` ve `multiply` fonksiyonları için prototipler bildirilir.

4. **Ana Fonksiyon:**
   - `main` fonksiyonu, iki giriş matrisini (`sparseMatrix1` ve `sparseMatrix2`) başlatır, bunlar için kompakt matrisler oluşturur ve ardından matris çarpımını gerçekleştirmek için `multiply` fonksiyonunu çağırır.

5. **Matrix Çarpımı Fonksiyonu (`multiply`):**
   - Bu fonksiyon, iki kompakt matrisi girdi olarak alır, matris çarpımını gerçekleştirir, sonucu normal bir matrise dönüştürür, sonuç için bir kompakt matris oluşturur ve sonucu ekrana yazdırır.

6. **Yazdırma Fonksiyonu (`print`):**
   - `print` fonksiyonu, bir kompakt matrisi ekrana yazdırmaktan sorumludur.


### Örnek Matrisler:

```c
int sparseMatrix1[_K][_L] = 
{ 
    {0, 10, 0, 5}, 
    {0, 2, 4, 0}, 
    {0, 0, 0, 0}, 
    {3, 0, 0, 7}, 
};

int sparseMatrix2[_L][_M] = 
{ 
    {1, 0, 0, 2}, 
    {0, 0, 3, 0}, 
    {0, 8, 0, 0}, 
    {5, 0, 10, 0}, 
};
```

### Sonuç:

Çarpımın sonucu, kompakt bir matris formatında görüntülenir.

### Not:

- Kod, seyrek matrisler için yer tasarrufu yapmak amacıyla kompakt bir temsil kullanır.
- Giriş matrislerini ve boyutlarını kendi gereksinimlerinize göre ayarladığınızdan emin olun.

---

