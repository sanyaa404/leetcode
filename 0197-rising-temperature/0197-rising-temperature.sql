select wtoday.id from Weather as wtoday
Join Weather as wyesterday
where datediff(wtoday.recordDate, wyesterday.recordDate) = 1 
AND wtoday.temperature > wyesterday.temperature;