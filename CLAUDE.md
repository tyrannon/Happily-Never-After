# Happily Never After - Claude Development Assistant Guide

## Project Overview
**Game:** Happily Never After  
**Type:** Overwatch-style hero shooter with dark fairy tale characters  
**Engine:** Unreal Engine 5.3+  
**Platform:** PC (initial), Console (planned)  
**Language:** C++ with Blueprint support  

## Quick Commands

### Build & Run
```bash
# Compile project
/Engine/Build/BatchFiles/Mac/Build.sh HappilyNeverAfter Mac Development

# Run editor
/Engine/Binaries/Mac/UnrealEditor.app HappilyNeverAfter.uproject

# Package game
/Engine/Build/BatchFiles/RunUAT.sh BuildCookRun -project=HappilyNeverAfter.uproject -platform=Mac
```

### Common Tasks
- **Create new hero class**: Inherit from `AHNACharacterBase`
- **Add new ability**: Create class inheriting from `UHNAAbilityBase`
- **Test networking**: Use `-game -server -log` for dedicated server

## Architecture Decisions

### Component System
- Heroes use component-based architecture
- Each major system (health, abilities, movement) is a separate component
- Allows for easy mixing and matching of hero capabilities

### Ability System
- Data-driven through DataAssets
- Abilities are objects, not functions
- Supports cooldowns, charges, and combo systems
- Network-replicated with prediction

### Networking Model
- Server-authoritative for all gameplay
- Client-side prediction for movement and abilities
- Lag compensation for projectiles
- Rollback netcode planned for Phase 2

## Current Implementation Status

### Completed Systems
- [x] Project structure
- [x] Character roster design (19 heroes)
- [x] Development roadmap

### In Progress
- [ ] Base character controller
- [ ] Ability system framework
- [ ] First hero implementation (Puss-in-Boots)

### Upcoming
- [ ] Combat system
- [ ] UI framework
- [ ] Networking foundation

## Code Patterns

### Creating a New Hero
```cpp
// 1. Create hero class
class HAPPILYNEVERAFTER_API APussInBoots : public AHNACharacterBase
{
    // Hero-specific code
};

// 2. Create DataAsset in editor
// 3. Configure abilities, stats, etc.
// 4. Reference in GameMode hero list
```

### Adding an Ability
```cpp
// 1. Create ability class
UCLASS()
class UBootSpringDash : public UHNAAbilityBase
{
    virtual void ActivateAbility(AHNACharacterBase* Character) override;
};

// 2. Add to hero's DataAsset
// 3. Bind to input in hero class
```

## Performance Considerations

### Target Metrics
- 60 FPS @ 1080p Medium settings
- Network bandwidth < 128kb/s per player
- Memory usage < 4GB
- Load times < 15 seconds

### Optimization Priorities
1. Reduce draw calls (instancing, atlasing)
2. LOD systems for characters/environments
3. Efficient ability replication
4. Smart culling systems

## Testing Procedures

### Before Committing
1. Run in PIE (Play in Editor) - no crashes
2. Test in Standalone - no editor dependencies
3. Check multiplayer - 2 clients + server
4. Profile performance - maintain 60 FPS
5. Verify no compiler warnings

### Hero Balance Testing
- TTK (Time to Kill) should be 1-3 seconds
- Abilities should have clear counterplay
- Movement abilities have 5-8 second cooldowns
- Ultimate abilities charge in 60-90 seconds

## Common Issues & Solutions

### Issue: Character not moving
- Check InputComponent bindings
- Verify MovementComponent is enabled
- Check possession by PlayerController

### Issue: Ability not replicating
- Ensure `UFUNCTION(Server, Reliable)` for activation
- Check `GetLifetimeReplicatedProps`
- Verify authority checks

### Issue: Performance drops
- Use `stat fps` and `stat unit`
- Check `profilegpu` for render bottlenecks
- Review tick functions for expensive operations

## File Naming Conventions

### C++ Files
- `HNA` prefix for all game classes
- `HNACharacterBase.h/.cpp` - Base classes
- `HNAPussInBoots.h/.cpp` - Specific implementations

### Assets
- `BP_` prefix for Blueprints
- `M_` for Materials
- `T_` for Textures
- `SM_` for Static Meshes
- `SK_` for Skeletal Meshes

### Maps
- `L_` prefix
- `L_Playground` - Testing map
- `L_MainMenu` - Menu map
- `L_Sherwood` - Game map

## Git Workflow

### Branches
- `main` - Stable builds only
- `develop` - Active development
- `feature/hero-name` - New hero implementation
- `fix/issue-description` - Bug fixes

### Commit Messages
```
feat: Add Puss-in-Boots dash ability
fix: Correct projectile collision on clients
docs: Update ability documentation
perf: Optimize ability replication
```

## Debug Commands

### Console Commands (~ key)
```
HNA.God - Invincibility
HNA.InfiniteAbilities - No cooldowns
HNA.DebugDamage 1 - Show damage numbers
HNA.DebugMovement 1 - Show movement vectors
HNA.ForceHero PussInBoots - Switch hero
stat fps - Show FPS
stat unit - Show frame times
```

## Resources

### Documentation
- [UE5 Docs](https://docs.unrealengine.com/5.3)
- [UE5 C++ API](https://docs.unrealengine.com/5.3/API)
- CHARACTER_ROSTER.md - Full hero details
- DEVELOPMENT_GUIDE.md - Development process

### Key Systems to Review
- `GameplayAbilitySystem` - For ability implementation reference
- `CharacterMovementComponent` - For movement mechanics
- `GameStateBase` - For match state management

## Next Steps

1. Set up version control with Git LFS
2. Create base project in Unreal Engine 5
3. Implement character movement system
4. Create first ability prototype
5. Test with multiple clients

## Notes

- Always prefer C++ for gameplay logic
- Use Blueprints for prototyping and designer tweaking
- Keep abilities modular and data-driven
- Test multiplayer early and often
- Profile performance regularly

---

Remember: This is a living document. Update it as the project evolves!