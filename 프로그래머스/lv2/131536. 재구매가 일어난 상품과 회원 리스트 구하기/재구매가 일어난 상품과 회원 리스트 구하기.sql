-- 코드를 입력하세요
SELECT distinct o1.user_id, o1.product_id
from online_sale o1, online_sale o2
where o1.user_id=o2.user_id and o1.product_id=o2.product_id and o1.online_sale_id<>o2.online_sale_id
order by o1.user_id asc, o1.product_id desc