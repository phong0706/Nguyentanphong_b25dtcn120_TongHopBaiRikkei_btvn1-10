CREATE TABLE CUSTOMERS (
    CustomerID INT PRIMARY KEY AUTO_INCREMENT,
    FullName VARCHAR(100) NOT NULL
);

CREATE TABLE ORDERS (
    OrderID INT PRIMARY KEY AUTO_INCREMENT,
    
    -- Tự động lấy ngày giờ hiện tại nếu không nhập
    OrderDate DATETIME DEFAULT CURRENT_TIMESTAMP, 
    
    -- Sử dụng số nguyên cho tiền tệ để tránh sai lệch
    TotalAmount BIGINT NOT NULL, 
    
    -- Cột liên kết với bảng CUSTOMERS
    CustomerID INT NOT NULL, 
    
    -- Thiết lập Khóa ngoại (Foreign Key)
    -- Đảm bảo đơn hàng phải thuộc về một khách hàng có thật
    CONSTRAINT FK_CustomerOrder 
        FOREIGN KEY (CustomerID) 
        REFERENCES CUSTOMERS(CustomerID)
);