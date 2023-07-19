-- 코드를 입력하세요
SELECT WAREHOUSE_ID, warehouse_name, address, IFNULL(freezer_yn,'N') as freezer_yn
from food_warehouse
where warehouse_name like '%경기%'
order by warehouse_id asc;