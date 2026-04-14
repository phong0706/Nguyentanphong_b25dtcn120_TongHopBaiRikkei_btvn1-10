ALTER TABLE USERS ADD COLUMN Phone_New VARCHAR(15);
-- Chia nhỏ để chạy nếu cần (ví dụ: mỗi lần 100.000 dòng) để tránh treo RAM
UPDATE USERS 
SET Phone_New = LPAD(Phone, 10, '0') 
WHERE Phone_New IS NULL;
-- 1. Xóa cột cũ (kiểu INT)
ALTER TABLE USERS DROP COLUMN Phone;
ALTER TABLE USERS CHANGE Phone_New Phone VARCHAR(15);