### 1 Testing Grounds Introduction ###

### Code Architecture Storing State ###

### 2 Testing Grounds GDD ###

+ The concept of the game
+ The rules of the game
+ Some of the asset requirements for the game
+ Identify possible technical challenges.

### 3 Using Git LFS (Large File Support) ###

+ The distinction between Git vs GitHub
+ Use Unreal’s toolbar & SourceTree
+ Enable Git Large File Support (LFS)
+ Setup on GitHub (no readme.md or initial commit)
+ Push to GitHub and share
+ Warning: may take a while on slow broadband.

### 4 Marketing & Markdown ###

+ Limitations of Unreal’s connection to GitHub
+ How to reset to previous commit to combine
+ Presenting your public GitHub page well
+ Using Markdown to enrich formatting.

### 5 Use git clean to Revert Project ###

+ An overview of the scene
+ How the First Person Character is composed
+ Adding a spiral staircase.

### 6 First Person Character Overview ###

### 8 The Third Person Character ###

+ Add a third person character to the scene
+ Caution about tidying files at this stage
+ Add a navmesh, and check it’s continuous.

### 9 Introducing AI Behaviour Trees ###

+ Setup a Blueprint AI controller class
+ Behaviour Trees controll AI execution flow
+ Blackboards hold AI instance data
+ How to associate a behaviour tree with an AI
+ Testing that our behavior tree is running.

### 10 Introducing AI Blackboard Data ###

+ Blackboard data is like member variables in code
+ Using blackboard data to set patrol points
+ Practice setting blackboard values in Blueprint
+ Test simple AI patrol behaviour.

### 11 Target Points and Patrol Routes ###

+ Add a variable to the NPC’s blueprint
+ How to make a variable an array in blueprint
+ Introducing Target Point actors
+ Using target points to specify patrol routes.

### 12 Using Any Actor for Waypoints ###

+ Actors are more general than target points
+ How to select an actor from another actor
+ Getting the AI Controller to set Blackboard data
+ Testing our characters go to a set waypoint.

### 13 Options for Grouping Actors ###

+ Use layers (usually used for visibility)
+ Use groups as a simple multi-select tool
+ Use tags, can be flexible but easy to forget
+ Use a parent Empty Actor, or a Folder
+ Group on game object (e.g. array on NPC)
+ The key is to know the pros and cons.

### 14 Blueprint Behaviour Tree Tasks ###

+ How to use Blackboard Key Selector variables
+ Creating new Tasks in Behaviour Trees
+ Pseudocode programming in Blueprint
+ How to use the Execute AI node
+ How to use the Finish Execute node.

### 15 Modular Arithmetic & Cycles ###

### 16 Performance Profiling 101 ###

+ The first rule of performance: “profile first”
+ Access profiler from Window > Developer Tools
+ Choose Session Front End
+ Select your running game session
+ Chose Profiler tab, and hit Data Preview
+ Search for your function and double-click.

### 17 C++ AI Behaviour Tree Tasks ###

+ Add “AIModule” and “GameplayTasks” to build
+ Inherit C++ class from **UBTTaskNode**
+ Override **ExecuteTask()**
+ Return **EBTNodeResult::Succeeded;**
+ Don’t try and extend in Blueprint
+ Use Blueprint XOR C++ for a given task.

### 18 Reading Blackboard Data in C++ ###

+ Expose a blackboard key selector in C++
+ **#include “BehaviorTree/BlackboardComponent.h”**
+ **OwnerComp.GetBlackboardComponent()**
+ Use **GetValueAsInt()** etc to get the value
+ You can now access blackboard data in C++.

### 19 The Consequences of Inheritance ###

+ We have coupled our AI ChoseNextWaypoint task to the Third Person Character.
+ We have also specialised our Blueprint class with a variable, PatrolPoints.
+ These dependencies are undesirable, but we will proceed with our conversion.

### 20 Converting Blueprint to C++ ###

+ **OwnerComp.GetAIOwner()** to get AI Controller
+ If you’re casting, you’re probably coupling
+ Use **.Num()** to get number of elements in **TArray**
+ Use **TODO** for reminders, to help you FOCUS
+ FOCUS = Follow One Course Until Successful.

### 21 Composition over Inheritance ###

+ We created PatrollingGuard by inheritance
+ How about if we want a patrolling tank?
+ Another option is to use an actor component
+ This is an age-old debate
+ Let’s get some real-world experience of the two
+ Convert to a component model.

### 21b Talking Head: What We've Covered So Far ###

+ What we've covered recently
+ What's coming up.

### 22 How to Delete a C++ Class ###

+ Yes it should be easier than this, tell Epic!
+ How to remove CPP files from browser in Unreal
+ The process for deleting C++ classes.

### 23 Instanced Materials ###

+ Also called Material Instances
+ These allow modification with little overhead
+ How to create an instanced material.

### 24 Introducing AI Perception ###

+ Use AI Perception, it’s newer than Pawn Sensing
+ How to add AI Perception to your controller
+ Use the apostrophe key ‘ to enable AI debug
+ Remember Shift + F1, F8, F11 etc.

### 25 OnTargetPerceptionUpdated Event ###

+ Use the On Target Perception Updated event
+ This reports the actor sensed
+ And the class of the sense (e.g. sight, hearing)
+ How to setup perception events.

### 26 AI Hearing Perception in Unreal ###

+ Hearing is a sense that compliments sight
+ How to set up AI Perception hearing sense
+ How to get hearing perception to trigger
+ Making your actor create a noise.

### 27 The Animation Starter Pack ###

+ The skeleton comprises the bones
+ Over the skeleton lays a skeletal mesh
+ Each vertex of the mesh connects to bone(s)
+ The animation tells the bones how to move
+ The bones tell the mesh how to move
+ The Animation BP controls the animations.

### 28 Changing a Character’s Animation ###

+ How to change a mesh’s animation class
+ Matching the animation’s mesh to…
+ … the mesh selected on the character
+ You can apply instance changes to blueprint
+ However be careful what you take with you
+ Solving “can’t save… graph is linked” error.

### 29 Customising a Character Blueprint ###

+ You can start with a off-the-shelf blueprint
+ We can then add our reusable components
+ Another way of getting our desired character.

### 30 Sub Behaviour Trees ###

+ Behaviour trees can get complex
+ We want to keep a consistent level of abstraction
+ Behaviour trees can run “sub” trees
+ This helps us organise our project.

### 31 Talking Head - Introducing Sam ###

+ Congratulations on getting this far in the course.
+ Recapping the AI work we have done so far.
+ Introducing the new instructor for the section: Sam.

### 31b Talking Head - Refactoring Superpowers ###

+ Why refactoring is so important.
+ Refactor skills give you the edge.
+ What’s coming up in the next lectures.

### 32 Simplifying Our Project ###

+ Deleting and Moving folders.
+ Ensuring deletion on the file-system.
+ Good file structure for Unreal.
+ Viewing the dependencies of an object.
+ How and when to fix redirectors.

### 33 Renaming & Moving CPP ###

+ Renaming CPP files.
+ How to deal with renaming blueprint parents.
+ Refactor class names in CPP.
+ Updating .generated.h files.

### 34 Solution: Renaming & Moving CPP ###

+ Repeating the renaming process.
+ Finishing our refactor.
+ Fixing CDO Constructor errors.

### 35 Holding a Gun with Skeletal Sockets ###

+ Reading existing source code for hints.
+ Creating a socket on a skeletal mesh.
+ Parenting a gun to that socket.
+ Removing unused assets.

### 35b Understanding Animation Blueprints ###

+ The major components.
+ How to preview animations.
+ Definition of an animation and pose.
+ Understanding the AnimGraph.
+ Playing a custom animation.

### 36 Creating Animation State Machines ###

+ Why state machines?
+ What are state machines?
+ What’s inside a UE4 state?
+ How to add transitions.
+ Adding a shooting state.

### 37 Movement Blend Spaces ###

+ What is a blend space?
+ How to create a movement blend space.
+ Examining the existing Jog blend space.
+ Replicating for Ironsights.

### 38 Offset Animations ###

+ Creating an offset animation.
+ Applying an offset to a base.
+ Conditional blend nodes.

### 39 Aiming Blend Spaces Offsets ###

+ Aim offset assets.
+ 1D vs 2D Aim offsets.
+ Editing an existing animation sequence.

### 40 Rotating with SetFocalPoint() ###

+ Revising Behaviour Tree tasks.
+ Making our character face us.
+ Using AIController’s SetFocalPoint()

### 41 Character Movement vs Rotation ###

+ More code reading.
+ Jumping between files in Visual Studio.
+ Difference between movement and rotation.
+ Mapping out complex systems.

### 42 Control Rotation for Aim ###

+ Getting the control rotation.
+ Focus Actor vs Focal Point
+ Splitting rotators and setting pitch.
+ Controlling Animation BP properties.

### 43 Behaviour Tree Decorators ###

+ Creating a decorator.
+ Sequence vs Select nodes.
+ Aborting decorators early.
+ Clearing blackboard keys from blueprint.
+ Patrolling, agro and following.

### 44 Behaviour Tree Services ###

+ Using decorators vs services.
+ Creating a service.
+ Deeper into behaviour tree states.
+ How to implement suspicion.
+ Giving our character breathing space.
+ Comparing BP Validity and NULL.

### 45 Tweaking AI Behaviour ###

+ Preventing Behaviour Tree flicker.
+ Creating mutually exclusive states.

### 46 Debugging AI Behaviour ###

+ Viewing behaviour while playing.
+ Using tags on Actors.
+ Revising interrupting tasks.
+ Adding in multiple actors.

### 47 Refactoring to a Gun Actor ###

+ Create a Gun actor.
+ Move the firing code over.
+ Revising refactoring.

### 48 Attaching Actors to Components ###

+ Revise spawning child actors.
+ Attaching actors to sub-components.
+ Attachment rule to sockets.

### 49 Configuring the Gun ###

+ Playing montage animations.
+ Connecting to actors in code.
+ Finishing our refactor.

### 50 Moving Files from LFS to Git ###

+ The pros and cons of LFS.
+ How to move files from LFS.
+ Tracking folder instead of extensions.
+ Where tracking happens.

### 51 To LFS or Not to LFS? ###

+ The pros and cons of LFS.
+ Organising your project for clarity.
+ How to deal with .umap assets.

### 52 Child Actor Components ###

+ Previewing the gun with the skeleton.
+ Positioning the gun.
+ Child actors with Blueprint.
+ Using Child Actor Components.

### 52b Introduction to Inverse Kinematics ###

+ Local vs component-space poses.
+ Understanding bone-space.
+ The principles of IK.
+ End effectors and Joint targets.
+ Mapping to the Two Bone IK node.

### 53 Inverse Kinematics with Animations ###

+ Using the Two Bone IK node.
+ Effectors vs Joint targets
