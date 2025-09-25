# BÀI TẬP MÔN: An toàn và bảo mật thông tin
## BÀI TẬP 1: 
# YÊU CẦU: 
## TÌM HIỂU CÁC PHƯƠNG PHÁP MÃ HÓA CỔ ĐIỂN
1. Caesar
2. Affine
3. Hoán vị
4. Vigenère
5. Playfair

### Với mỗi phương pháp, hãy tìm hiểu: 
1. Tên gọi
2. Thuật toán mã hóa, thuật toán giải mã
3. Không gian khóa
4. Cách phá mã (mà không cần khóa)
5. Cài đặt thuật toán mã hóa và giải mã bằng code C++ và băng html+css+javascript

# BÀI LÀM: 
## 1. Phương pháp mã hóa Caesar
### 1.1 Tên gọi 
- Mật mã Caesar hay còn gọi là mật mã chuyển vị là một trong những kỹ thuật mã hóa đơn giản và phổ biến nhất. Đây là một dạng mật mã thay thế, trong mỗi ký tự trên bản rõ sẽ được thay bằng một ký tự khác có vị trí cách nó một khoảng xác định trong bảng chữ cái (khoảng này được gọi là khóa K). Tên của kỹ thuật mã hóa này được đặt theo tên của Julius Caesar, người đã sử dụng phương pháp mã hóa này trong các thư từ bí mật của mình

### 1.2 Thuật toán mã hóa và giải mã
#### Thuật toán mã hóa: 
- Ta sẽ sử dụng bảng chữ cái có 26 ký tự từ A đến Z và mỗi chữ cái sẽ gán tuần tự với một số nguyên tương ứng từ 0 đến 25 (A->0, B->1,... Z->25). Mã hóa một chữ cái x bằng cách dịch chuyển n vị trí được mô tả bằng phương thức toán học sau: <br>
**Ek(x) = (x + k) mode 26** <br>
Trong đó:  
*k là khóa - độ dịch chuyển*    
*x là bản rõ - ký tự cần mã hóa*
*E là bản mã*  
<img width="587" height="178" alt="image" src="https://github.com/user-attachments/assets/f4b6f7c4-1a75-4c6d-951e-16afaf38102f" /> 

#### Thuật toán giải mã: 
- Thuật toán giải mã sẽ được ngược lại với thuật toán mã hóa, nó thực hiện như sau:  
**Dk(x) = (x - k) mode 26**  
Trong đó:  
*D là bản rõ*  
*x là bản mã - ký tự cầm giải mã*  
*k là khóa - độ dịch chuyển*  

### 1.3 Không gian khóa 
- Nếu dùng bảng 26 chữ cái thì số khóa là 26 khóa (k = 25)
- Nhưng k = 0 và k = 26 cho cùng một vị trí hoán vị nên thực tế chỉ có 25 khóa hữu dụng nếu bỏ k = 0 (không dịch)  
 ==> Không gian khóa của thuật toán mã hóa Caesar rất nhỏ và dễ bị tấn công

### 1.4 Cách phá mã mà không cần khóa
Do không gian khóa của thuật toán này rất nhỏ nên nó dễ bị tấn công bằng nhiều cách như:  
+ **Tấn công vét cạn (Brute-force)**: Cách này sẽ thử tất cả 26 khả năng và đọc kết quả
+ **Phân tích tần suất**: Trong các văn bản dài thì tần suất xất hiện của các chữ cái cố định sẽ nhiều, vì thế mà các hacker có thể so sánh chữ cái phổ biến nhất trong đoạn mã từ đó suy đoán ra chữ cái nào đã bị thay thế và tìm ra khóa k.
+ **Known-plaintext / crib**: Phương pháp này là nếu biết một đoạn nhỏ của bản rõ thì có thể suy ra khóa k ngay

### 1.5 Cài đặt thuật toán mã hóa và giải mã  
#### Mã hóa bằng html + css + javascript:  
<img width="1511" height="755" alt="image" src="https://github.com/user-attachments/assets/f1fd090a-f4bf-402b-bc45-82c3bb0e80ed" />  

### Giải mã bằng html + css + javascript:  
<img width="1243" height="702" alt="image" src="https://github.com/user-attachments/assets/ddab456b-4859-41de-b100-8cc1e6646668" />  

### Mã hóa và giải mã bằng C++:  
<img width="812" height="328" alt="image" src="https://github.com/user-attachments/assets/2d49a48f-a280-4c8c-8755-aa54bf0ad55e" />  

## 2. Phương pháp mã hóa Affine
### 2.1 Tên gọi
- Mật mã Affine là một dạng mật mã thay thế dùng một bảng chữ cái trong đó mỗi chữ cái được ánh xạ tới một số, sử dụng hàm tuyến tính trong số học module.

### 2.2 Thuật toán mã hóa và giải mã  
#### Mã hóa:  
- Biểu diễn mỗi chữ cái bằng số từ 0 đến 25 (A = 0, B = 1,..., Z = 25).
- Dùng hàm mã hóa: ***E(x) = (a.x + b) mode 26***
  *Trong đó*:
  - *x là giá trị số của chữ cái bản rõ*
  - *a, b là hai số nguyên tạo thành khóa.*
  - *a phải thỏa mãn điều kiện: gcd(a,26) = 1 (a và 26 phải là nguyên tố cùng nhau) để đảm bảo tồn tại nghịch đảo.*  

### Giải mã: 
- Dùng hàm giải mã: ***D(y) = a^(-1).(y-b) mode 26***
  *Trong đó:*
  - *y là giá trị số của chữ cái bản mã.*
  - *a^(-1) là nghịch đảo của a theo module 26 (là a.a^(-1) ≡ 1 mode 26).*

### 2.3. Không gian khóa  
- Không gian khóa của phương pháp mã hóa Affine có khóa gồm cặp số (a,b) với:
  - a ∈ {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25} (12 giá trị thỏa mãn gcd(a,26) = 1).
  - b ∈ {0, 1,..., 25}.
  - ==> Có tổng 213 khóa (12 x 26).

### 2.4 Cách phá mã không cần khóa
- ***Phương pháp vét cạn (Brute-force)***: Thử tất cả 312 cặp khóa (a, b) sau đó giải mã bản mã
- ***Phân tích tần xuất***: So sánh tần suất xuất hiện của các chữ cái trong bản mã với tần suất chuẩn của bản rõ ==> Suy đoán các chữ cái bị thay thế và tìm ra khóa.

### 2.5 Cài đặt thuật toán mã hóa và giải mã  
#### Mã hóa bằng html + css+ javascript:  
<img width="1329" height="777" alt="image" src="https://github.com/user-attachments/assets/d320a81e-90e0-4693-8a2c-f7e0f9c6b9c5" />  

#### Giải mã bằng html + css + javascript: 
<img width="1211" height="763" alt="image" src="https://github.com/user-attachments/assets/9d65b795-8b83-4e28-a051-4beface86d36" />  

#### Mã hóa và giải mã bằng C++:  
<img width="843" height="465" alt="image" src="https://github.com/user-attachments/assets/783682e2-da62-462f-9497-d946a5fbf51a" />  

## 3. Phương pháp mã hóa hoán vị
### 3.1 Tên gọi 
- Mã hóa hoán vị

### 3.2 Thuật toán mã hóa và giải mã
#### Nguyên lý: 
- Chia văn bản thành các block có độ dài n (n = độ dài khóa / hoán vị)
- Với mỗi block, tái sắp xếp các ký tự theo một hoán vị P
- Nếu block cuối không đủ n ký tự thì pad (ví dụ 'x')

#### Mã hóa: 
- Với mỗi block B (b0..b_{n-1}, tạo ciphertext block C sao cho C[i] = B[ P[i] ]

#### Giải mã: 
- Dùng hoán vị nghịch đảo P^(-1) để đặt các ký tự về vị trí ban đầu: ***B[i] = C[P^(-1)[i]]***

### 3.3 Không gian khóa 
- Nếu khóa là một hoán vị có độ dài n thì số lượng khóa sẽ = n!, nếu n nhỏ thì n! cũng sẽ nhỏ và dễ bị tấn công vét cạn. Nếu n lớn thì n! cũng lớn, không gian khóa rất to.

### 3.4 Cách phá mã không cần khóa
- ***Vét cạn (Brute-force)***: Thử tất cả các hoán vị có thể
- ***Phân tích cấu trúc***: Dựa vào độ dài khối và tần suất xuất hiện của các ký tự để đoán 

### 3.5 Cài đặt thuật toán mã hóa và giải mã 
#### Mã hóa bằng html+css+javascript:  
<img width="1244" height="754" alt="image" src="https://github.com/user-attachments/assets/57295130-6096-4f12-9e3e-950e732bebd1" />  

#### Giải mã bằng html+css+javascript
<img width="1315" height="804" alt="image" src="https://github.com/user-attachments/assets/14c343b6-4b7f-4987-8baf-23657e6fbf37" />  

#### Mã hóa và giải mã bằng C++: 
<img width="1189" height="754" alt="image" src="https://github.com/user-attachments/assets/5e552e85-723d-4609-9c74-4e82eb611e8f" />
  
## 4. Phương pháp mã hóa Vigenère
### 4.1 Tên gọi
- Mã hóa Vigenere cipher

### 4.2 Thuật toán mã hóa và giải mã
#### Thuật toán mã hóa: 
- Biểu diễn mỗi chữ cái bằng số từ 0 đến 25 (A = 0, B = 1,..., Z = 25)
- Công thức: ***Ci = (Pi + Ki) mode 26***
  *Trong đó*:
  - P là bản rõ
  - K là khóa
  - C là bản mã

#### Thuật toán giải mã: 
- Công thức: ***Pi = (Ci - Ki + 26) mode 26***

### 4.3 Không gian khóa
- Nếu key dài m (m chữ cái, mỗi chữ có 26 khả năng), thì không gian khóa là 26^m. Nếu key có đỗ dài thay đổi thì không gian khóa sẽ lớn và phức tạp hơn.

### 4.4 Cách phá mã không cần khóa
- ***Phân tích tần suất***: phân chia bản mã thành các nhóm theo chu kỳ khóa để tìm độ dài khóa
- ***Kasiski examination***: tìm các chuỗi lặp trong ciphertext; khoảng cách giữa các lần lặp thường chia hết cho độ dài khóa -> suy ra độ dài khóa.
- ***Friedman test***: Tính chỉ số trùng lặp

### 4.5 Cài đặt thuật toán mã hóa và giải mã
#### Mã hóa bằng html+css+javascript:   
<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/aa25197a-293c-4d1e-9b10-ea3122b243c2" />

#### Giải mã bằng html+css+javascript:  
<img width="1246" height="762" alt="image" src="https://github.com/user-attachments/assets/a12c0889-1343-40c7-89d8-d0d544b7051c" />
 
#### Mã hóa và giải mã bằng C++:    
<img width="979" height="744" alt="image" src="https://github.com/user-attachments/assets/9627815d-8394-420e-b5d1-73fe2aceb39c" />  

## 5. Phương pháp mã hóa PlayFair
### 5.1 Tên gọi






