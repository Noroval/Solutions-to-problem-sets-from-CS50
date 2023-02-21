-- write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred

SELECT title
FROM movies, stars, people
WHERE movies.id = stars.movie_id
AND stars.person_id = people.id
AND people.name = 'Johnny Depp'
AND title IN
   (SELECT title
    FROM movies, stars, people
    WHERE movies.id = stars.movie_id
    AND stars.person_id = people.id
    AND people.name = 'Helena Bonham Carter');