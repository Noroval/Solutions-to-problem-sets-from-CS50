-- write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred

SELECT DISTINCT name
FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND movies.id IN
   (SELECT movies.id
    FROM movies, stars, people
    WHERE movies.id = stars.movie_id
    AND stars.person_id = people.id
    AND people.name = 'Kevin Bacon' AND people.birth = 1958)
AND people.name != 'Kevin Bacon';