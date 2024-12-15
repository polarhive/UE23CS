// Import MongoDB client
const { MongoClient } = require('mongodb');

// MongoDB connection URI
const uri = "mongodb://localhost:27017";

// Connect to MongoDB
MongoClient.connect(uri, { useNewUrlParser: true, useUnifiedTopology: true })
    .then(client => {
        const db = client.db('newdb');
        const collection = db.collection('student');

        // Insert One - Adding a single document
        collection.insertOne({ name: 'Alice', srn: '123', dept: 'CSE' })
            .then(result => console.log('Inserted one document: ', result))
            .catch(err => console.error('Error inserting one document:', err));

        // Insert Many - Adding multiple documents
        collection.insertMany([
            { name: 'Bob', srn: '124', dept: 'CSE' },
            { name: 'Tim', srn: '125', dept: 'ECE' }
        ])
            .then(result => console.log('Inserted multiple documents: ', result.insertedIds))
            .catch(err => console.error('Error inserting multiple documents:', err));

        // Find - Finding all documents
        collection.find({}).toArray()
            .then(results => console.log('All students: ', results))
            .catch(err => console.error('Error finding documents:', err));

        // Find One - Finding a specific document
        collection.findOne({ srn: '123' })
            .then(result => console.log('Found one student: ', result))
            .catch(err => console.error('Error finding one document:', err));

        // Update One - Updating a specific document
        collection.updateOne({ name: 'Alice' }, { $set: { dept: 'ECE' } })
            .then(result => console.log('Updated one document: ', result.modifiedCount))
            .catch(err => console.error('Error updating one document:', err));

        // Update Many - Updating multiple documents
        collection.updateMany({ dept: 'ECE' }, { $set: { dept: 'CSE' } })
            .then(result => console.log('Updated many documents: ', result.modifiedCount))
            .catch(err => console.error('Error updating multiple documents:', err));

        // Delete One - Deleting a specific document
        collection.deleteOne({ srn: '125' })
            .then(result => console.log('Deleted one document: ', result.deletedCount))
            .catch(err => console.error('Error deleting document:', err));

        // Close the connection
        client.close();
    })
    .catch(err => console.error('Error connecting to MongoDB:', err));

