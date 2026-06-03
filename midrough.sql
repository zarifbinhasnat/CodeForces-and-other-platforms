SELECT (COUNT(work_id) * 100.0 / (SELECT COUNT(*) FROM work)) AS display_percentage
FROM work
WHERE museum_id IS NOT NULL;



SELECT country, COUNT(museum_id) AS museum_count
FROM museum
GROUP BY country
ORDER BY museum_count DESC
LIMIT 1;



SELECT artist_id, style, COUNT(work_id) AS works_count
FROM work
GROUP BY artist_id, style;
  

  SELECT museum_id, COUNT(DISTINCT artist_id) AS distinct_artists_count
FROM work
GROUP BY museum_id
ORDER BY distinct_artists_count DESC
LIMIT 1;



SELECT museum_id, COUNT(work.work_id) AS contemporary_works_count
FROM work
JOIN artist ON work.artist_id = artist.artist_id
WHERE artist.birth > 1950
GROUP BY museum_id
ORDER BY contemporary_works_count DESC
LIMIT 1;

SELECT style, EXTRACT(YEAR FROM creation_date) AS year, COUNT(work_id) AS count
FROM work
GROUP BY style, year
ORDER BY style, year;


SELECT artist_id, AVG(LENGTH(name) - LENGTH(REPLACE(name, ' ', '')) + 1) AS avg_words
FROM work
GROUP BY artist_id
HAVING avg_words > 4;









--9
SELECT nationality, EXTRACT(YEAR FROM birth) AS birth_year, COUNT(artist_id) AS artist_count
FROM artist
GROUP BY nationality, birth_year
ORDER BY birth_year;



--10

SELECT museum_id, COUNT(DISTINCT style) AS style_count
FROM work
GROUP BY museum_id
ORDER BY style_count DESC
LIMIT 1;
