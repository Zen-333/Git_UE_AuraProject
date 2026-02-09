Aura - GAS Learning Project

A comprehensive learning project demonstrating Unreal Engine's Gameplay Ability System (GAS) implementation for an action RPG.

Overview

Aura is an educational project built with Unreal Engine 5 that explores advanced gameplay systems including ability management, attribute systems, UI/UX patterns, and multiplayer functionality. The project implements a complete RPG framework with character progression, spell systems, and AI enemies.

Core Systems

Gameplay Ability System (GAS)

Custom ability implementation with damage, projectile, and beam spells
Scalable damage calculations with debuffs and resistances
Passive ability system with visual feedback
Ability progression and equipment system

Character System

Player and enemy character base classes
Character class differentiation (Elementalist, Warrior, Ranger)
Level-based attribute scaling
Death and respawn mechanics

Attribute System

Primary attributes (Strength, Intelligence, Resilience, Vigor)
Derived secondary attributes (Armor, Critical Hit, Block Chance)
Elemental resistances (Fire, Lightning, Arcane, Physical)
Custom attribute calculations using MMC

UI Framework

MVVM pattern implementation for save/load system
Widget controllers for overlay, attributes, and spell menus
Dynamic damage numbers and visual feedback
Load screen with save slot management

AI System

Behavior Tree implementation
AI controller with blackboard integration
Enemy spawn system with difficulty scaling

Save System

Persistent character progression
World state serialization
Multiple save slot support
Checkpoint system

Technical Highlights

Network Replication: Properly replicated attributes and abilities
Gameplay Effects: Custom effect context for advanced combat mechanics
Data-Driven Design: Data assets for abilities, attributes, and character classes
Modular Architecture: Interfaces for combat, highlighting, and save functionality

Project Structure

Source/Aura/
├── Private/
│   ├── AbilitySystem/      # GAS implementation
│   ├── Character/          # Character classes
│   ├── Player/            # Player-specific classes
│   ├── UI/                # UI widgets and controllers
│   └── Game/              # Game mode and instance
└── Public/                # Header files

Key Features

Multiple spell types (projectile, beam, radial damage)
Character progression with XP and leveling
Spell point and attribute point systems
Equipment slots for abilities
Status effects and debuffs
Save/load functionality
AI enemy behaviors

Educational Value
This project demonstrates best practices for:

Implementing GAS in production-quality code
Structuring large-scale Unreal projects
Network replication patterns
UI architecture with MVVM
Data-driven game design

Requirements

Unreal Engine 5.x
C++ compiler compatible with UE5
Gameplay Ability System plugin


This is a learning project and not intended for commercial use.