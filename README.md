This repository is for all software team related stuff, including code and organisational documents.

Here is our branching structure:

- master: our release branch: you can't push to this
- admin: a branch for adding documentation files etc.
- develop: the most up to date version of our software

When you do any work, you should:

- create a branch of the form "firstname initial / what you're working on" (without spaces) - e.g. davidd/servicebugfix
- make sure your branch name is relevant, and don't make changes to anything else on that branch
- pull the most up-to-date version of develop into your branch
- when you've finished your work, if it compiles and runs, submit a merge request back into develop
- if there are merge conflicts, make sure you resolve them properly without breaking anyone else's work
- else just leave the merge request for someone else to resolve

If you're not confident with git, here's a good course: https://www.udacity.com/course/how-to-use-git-and-github--ud775

Here is the directory structure of the repo:

- docs contains all code documentation
- docs/reqs contains requirements documents
- docs/uml contains UML diagrams
- admin contains administration documents such as the Gantt chart
- admin/notes contains copies of notes taken during meetings
- admin/resources.docx contains all of the links Paul puts on Facebook
- arduino contains the most up-to-date version of the Arduino libraries and sketches
- code contains any other code which is being used for development (e.g. old code, example code, code which is too buggy 
			to add to the library, etc.)

In order to work on Arduino code in the Arduino IDE, you should set the arduino directory as your sketchbook directory in 
the IDE preferences. Otherwise you will not be able to #include the library files.

Up-to-date version of the Gantt chart can be found here: 
https://app.ganttpro.com/shared/token/63cc6f406f1354dc090faf8d852b37b043d804f53dbf99441e7f3a6c9c081e6f
