#!/bin/bash

# Start the Apache service
service apache2 start

# Drop into an interactive shell and execute the required commands
/bin/bash -c "
nvim /var/www/html/index.html;
nvim /etc/apache2/apache2.conf;
service apache2 restart;
exec bash
"
