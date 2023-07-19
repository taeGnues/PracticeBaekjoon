-- 코드를 입력하세요
SELECT a.author_id, a.author_name, b.category, sum(b.price * s.sales) as 'TOTAL_SALES'
FROM AUTHOR a, BOOK b, BOOK_SALES s 
WHERE a.author_id = b.author_id and b.book_id=s.book_id and YEAR(s.sales_date) = '2022' and MONTH(s.sales_date) = 1
GROUP BY a.author_id, a.author_name, b.category
ORDER BY a.author_id asc, b.category desc;