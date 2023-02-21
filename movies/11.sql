-- write a SQL query to list the titles of the five highest rated movies (in order) that Chadwick Boseman starred in, starting with the highest rated

SELECT title
FROM movies, ratings, stars, people
WHERE movies.id = ratings.movie_id
AND movies.id = stars.movie_id
AND stars.person_id = people.id
AND people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;