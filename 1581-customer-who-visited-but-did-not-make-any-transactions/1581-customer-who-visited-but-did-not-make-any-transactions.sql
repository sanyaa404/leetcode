select customer_id, count(visit_id) as count_no_trans from Visits
where visit_id not in (   
    select v.visit_id from Visits as v 
    join Transactions as t 
    where v.visit_id = t.visit_id)
group by customer_id;