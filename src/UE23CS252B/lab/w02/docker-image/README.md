### Build and Run the Container

Build the Docker image:
```bash
docker build -t server-ubuntu-apache .
```

Run the container interactively:
```bash
docker run -it --rm server-ubuntu-apache
```

Visit your site (IP may vary):

```plain
http://172.17.0.2/
```
