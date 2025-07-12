# 🎮 Happily Never After

A dark, twisted take on beloved fairy tales reimagined as an Overwatch-style hero shooter built in Unreal Engine 5.

## 🏰 Game Overview

In a world where fairy tales took a darker turn, heroes and villains clash in team-based combat. Play as reimagined characters like the sword-wielding Puss-in-Boots, the huntress Red Riding Hood, or the monstrous Big Bad Wolf in fast-paced 6v6 battles.

### Key Features
- 19+ unique fairy tale heroes across Damage, Tank, and Support roles
- Ability-based combat with ultimates
- Team-based objectives
- Dark, stylized art direction
- Cross-platform play (planned)

## 🚀 Quick Start

### Prerequisites
- Unreal Engine 5.3 or later
- Visual Studio 2022 (Windows) or Xcode (Mac)
- Git with Git LFS
- 50GB+ free disk space

### Setup
```bash
# Clone the repository
git clone https://github.com/yourusername/happily-never-after.git
cd happily-never-after

# Initialize Git LFS
git lfs install
git lfs pull

# Generate project files
# Mac
/Path/To/UnrealEngine/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh -project="HappilyNeverAfter.uproject" -game

# Windows
"C:\Path\To\UnrealEngine\Engine\Build\BatchFiles\GenerateProjectFiles.bat" -project="HappilyNeverAfter.uproject" -game
```

### Running the Game
1. Open `HappilyNeverAfter.uproject` in Unreal Engine
2. Press Play in Editor (PIE) or Alt+P
3. For multiplayer testing: Use the Multiplayer Options dropdown

## 🎭 Featured Heroes

### Damage
- **Puss-in-Boots** - Agile duelist with dash resets
- **Robin Hood** - Precision archer with crowd control
- **Little Red Riding Hood** - Close-range brawler with stealth

### Tank  
- **Big Bad Wolf** - Self-sustaining brawler with hook
- **The Beast** - Anchor tank with massive shield
- **Rapunzel** - Barrier tank with damage ramping

### Support
- **Fairy Godmother** - Main healer with resurrect
- **Pied Piper** - Area healer with speed boost
- **Cheshire Cat** - Utility support with invisibility

[Full roster in CHARACTER_ROSTER.md](CHARACTER_ROSTER.md)

## 🛠️ Development

### Project Structure
```
HappilyNeverAfter/
├── Source/          # C++ source code
├── Content/         # Game assets
├── Config/          # Configuration files
└── Documentation/   # Development docs
```

### Key Documents
- [DEVELOPMENT_GUIDE.md](DEVELOPMENT_GUIDE.md) - Comprehensive development guide
- [CHARACTER_ROSTER.md](CHARACTER_ROSTER.md) - Full hero details and abilities
- [CLAUDE.md](CLAUDE.md) - AI assistant integration guide

### Building from Source
```bash
# Mac
/Engine/Build/BatchFiles/Mac/Build.sh HappilyNeverAfter Mac Development

# Windows
Engine\Build\BatchFiles\Build.bat HappilyNeverAfter Win64 Development
```

## 🎯 Gameplay

### Game Modes (Planned)
- **Fairy Tale Siege** - Attack/Defend castle objectives
- **Enchanted Payload** - Escort the magic carriage
- **Storybook Control** - King of the Hill with rotating points
- **Ever After Elimination** - Round-based elimination

### Core Mechanics
- Hero-specific abilities with cooldowns
- Ultimate abilities that charge over time
- Role-based team composition
- Objective-focused gameplay

## 🔧 Technical Details

- **Engine**: Unreal Engine 5.3+
- **Platforms**: PC (initial), Console (planned)
- **Networking**: Dedicated servers with client prediction
- **Target Performance**: 60 FPS @ 1080p medium settings

## 📊 Development Status

### Current Phase: Foundation
- [x] Project setup and documentation
- [x] Character roster design
- [ ] Base movement system
- [ ] Ability framework
- [ ] First playable hero

### Roadmap
1. **Q1 2024**: Core mechanics and 3 heroes
2. **Q2 2024**: Networking and 6 more heroes
3. **Q3 2024**: First map and game mode
4. **Q4 2024**: Closed beta

## 🤝 Contributing

We welcome contributions! Please see our [Contributing Guidelines](CONTRIBUTING.md) (coming soon).

### Code Style
- Follow [Unreal Engine Coding Standards](https://docs.unrealengine.com/5.0/en-US/epic-cplusplus-coding-standard-for-unreal-engine/)
- Use meaningful commit messages
- Test multiplayer functionality before submitting

## 📝 License

This project is currently under development. License TBD.

## 🙏 Acknowledgments

- Inspired by Overwatch and Team Fortress 2
- Built with Unreal Engine 5
- Community feedback and support

---

*"And they all lived happily never after..."* 🏰⚔️