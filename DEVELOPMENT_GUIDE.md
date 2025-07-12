# Happily Never After - Development Guide

## 🎮 Project Overview

**Game Title:** Happily Never After  
**Genre:** Hero-based Team Shooter  
**Engine:** Unreal Engine 5.3+  
**Platform:** PC (Initial), Console (Phase 2)  
**Team Size:** Solo Developer  
**Development Machine:** M4 MacBook Air  

---

## 🏗️ Development Philosophy

### Core Principles
1. **Iterative Development**: Ship small, test often
2. **Performance First**: Target 60 FPS on mid-range hardware
3. **Modular Architecture**: Components over monoliths
4. **Data-Driven Design**: Designers shouldn't need programmers
5. **Player-Centric**: Fun trumps realism

### Development Mantras
- "Make it work, make it right, make it fast"
- "If it's not fun after 10 seconds, it won't be fun after 10 hours"
- "Every ability should feel impactful"

---

## 📁 Project Structure

```
HappilyNeverAfter/
├── Source/
│   ├── HappilyNeverAfter/
│   │   ├── Private/
│   │   │   ├── Characters/
│   │   │   │   ├── HNACharacterBase.cpp
│   │   │   │   ├── Heroes/
│   │   │   │   │   ├── PussInBoots/
│   │   │   │   │   ├── RobinHood/
│   │   │   │   │   └── RedRidingHood/
│   │   │   ├── Abilities/
│   │   │   │   ├── HNAAbilitySystemComponent.cpp
│   │   │   │   ├── HNAAbilityBase.cpp
│   │   │   │   └── Abilities/
│   │   │   ├── GameModes/
│   │   │   ├── UI/
│   │   │   └── Weapons/
│   │   └── Public/
│   │       └── [Mirror structure of Private]
├── Content/
│   ├── Characters/
│   ├── Maps/
│   ├── UI/
│   ├── VFX/
│   ├── Audio/
│   └── DataAssets/
├── Plugins/
├── Documentation/
└── Config/
```

---

## 🚀 Development Phases

### Phase 1: Foundation (Weeks 1-2)
- [x] Project setup with version control
- [ ] Base character movement (WASD + Mouse)
- [ ] Basic projectile system
- [ ] Health/damage framework
- [ ] Debug HUD

### Phase 2: Core Combat (Weeks 3-4)
- [ ] Ability system architecture
- [ ] Cooldown management
- [ ] Hit detection & feedback
- [ ] Death/respawn system
- [ ] Basic UI elements

### Phase 3: First Hero (Weeks 5-6)
- [ ] Implement Puss-in-Boots
- [ ] All four abilities functional
- [ ] Basic animations
- [ ] Sound effects
- [ ] Playtesting framework

### Phase 4: Networking Foundation (Weeks 7-8)
- [ ] Basic client-server architecture
- [ ] Character replication
- [ ] Ability synchronization
- [ ] Lag compensation
- [ ] Network debugging tools

### Phase 5: Hero Roster (Weeks 9-12)
- [ ] 3 Damage heroes
- [ ] 2 Tank heroes
- [ ] 2 Support heroes
- [ ] Hero selection screen
- [ ] Balance iteration

### Phase 6: First Map (Weeks 13-14)
- [ ] Graybox geometry
- [ ] Spawn systems
- [ ] Objective logic
- [ ] Map flow testing
- [ ] Basic environment art

### Phase 7: Polish (Weeks 15-16)
- [ ] VFX implementation
- [ ] Audio integration
- [ ] UI polish
- [ ] Performance optimization
- [ ] Bug fixing

---

## 🛠️ Technical Architecture

### Character System

```cpp
// Base character class structure
UCLASS()
class HAPPILYNEVERAFTER_API AHNACharacterBase : public ACharacter
{
    GENERATED_BODY()
    
protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UHNAAbilitySystemComponent* AbilitySystem;
    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
    class UHNAHealthComponent* HealthComponent;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    class UHNAHeroDataAsset* HeroData;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TSubclassOf<class UHNAHeroHUD> HeroHUDClass;
};
```

### Ability System

```cpp
// Ability base class
UCLASS()
class HAPPILYNEVERAFTER_API UHNAAbilityBase : public UObject
{
    GENERATED_BODY()
    
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Cooldown = 5.0f;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float Damage = 0.0f;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    EAbilityType AbilityType;
    
    UFUNCTION(BlueprintCallable)
    virtual void ActivateAbility(AHNACharacterBase* Character);
    
    UFUNCTION(BlueprintCallable)
    virtual bool CanActivateAbility() const;
};
```

### Data-Driven Heroes

```cpp
// Hero configuration via DataAssets
UCLASS()
class HAPPILYNEVERAFTER_API UHNAHeroDataAsset : public UPrimaryDataAsset
{
    GENERATED_BODY()
    
public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText HeroName;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MaxHealth = 200.0f;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    float MovementSpeed = 600.0f;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<TSubclassOf<UHNAAbilityBase>> Abilities;
};
```

---

## 🎯 Coding Standards

### Naming Conventions
- **Classes**: PascalCase with prefix (AHNACharacterBase)
- **Functions**: PascalCase (ActivateAbility)
- **Variables**: PascalCase for UPROPERTY, camelCase for locals
- **Constants**: SCREAMING_SNAKE_CASE
- **Blueprints**: BP_PrefixedName

### Code Style
```cpp
// Good example
void AHNACharacterBase::TakeDamage(float DamageAmount, AController* EventInstigator)
{
    if (!CanTakeDamage())
    {
        return;
    }
    
    const float ActualDamage = CalculateDamage(DamageAmount);
    HealthComponent->ApplyDamage(ActualDamage);
    
    OnDamageTaken.Broadcast(ActualDamage, EventInstigator);
}
```

### Blueprint Guidelines
- Keep Blueprint logic minimal
- Use C++ for gameplay systems
- Blueprints for:
  - UI logic
  - VFX/Audio triggers
  - Designer tweaking
  - Prototyping

---

## 🐛 Debugging Tools

### Console Commands
```
// Development commands
HNA.God - God mode
HNA.DebugAbilities - Show ability debug info
HNA.DebugDamage - Show damage numbers
HNA.DebugNetworking - Network debug overlay
HNA.TimeScale [float] - Slow/speed up time
```

### Debug Categories
```cpp
DEFINE_LOG_CATEGORY_STATIC(LogHNACharacter, Log, All);
DEFINE_LOG_CATEGORY_STATIC(LogHNAAbility, Log, All);
DEFINE_LOG_CATEGORY_STATIC(LogHNACombat, Log, All);
DEFINE_LOG_CATEGORY_STATIC(LogHNANetwork, Log, All);
```

---

## 📊 Performance Targets

### Minimum Specs
- **CPU**: Intel i5-8400 / AMD Ryzen 5 2600
- **GPU**: GTX 1060 / RX 580
- **RAM**: 8GB
- **Target**: 60 FPS @ 1080p Medium

### Optimization Guidelines
1. **Draw Calls**: < 3000 per frame
2. **Triangle Count**: < 5M visible
3. **Texture Memory**: < 2GB VRAM
4. **Network**: < 128kb/s per player

### Profiling Tools
- Unreal Insights
- RenderDoc
- Stat commands
- Network profiler

---

## 🎮 Playtesting Framework

### Test Scenarios
1. **Hero Balance**: 1v1 duels
2. **Team Fights**: 6v6 battles
3. **Ability Interactions**: Edge cases
4. **Network Stress**: High latency/packet loss
5. **Performance**: Worst-case scenarios

### Metrics to Track
- Time to Kill (TTK)
- Ability usage rates
- Win rates per hero
- Player movement heatmaps
- Performance hotspots

---

## 📝 Documentation Standards

### Code Documentation
```cpp
/**
 * Activates the hero's ability at the specified index
 * @param AbilityIndex - Index of ability to activate (0-3)
 * @param TargetLocation - World location for targeted abilities
 * @return True if ability was successfully activated
 */
bool ActivateAbility(int32 AbilityIndex, FVector TargetLocation);
```

### Asset Documentation
- Every asset needs a clear naming convention
- Document unusual implementation choices
- Keep a CHANGELOG for major systems

---

## 🚢 Build & Deployment

### Build Configurations
- **Development**: Full debugging, editor support
- **DebugGame**: Debugging in standalone
- **Shipping**: Optimized for release

### Platform Considerations
- **Windows**: Primary platform
- **Mac**: Development support (Apple Silicon)
- **Linux**: Server builds
- **Console**: Future consideration

---

## 📚 Resources & References

### Unreal Engine
- [UE5 Documentation](https://docs.unrealengine.com/)
- [Network Compendium](https://docs.unrealengine.com/5.0/en-US/networking-overview-for-unreal-engine/)
- [Gameplay Framework](https://docs.unrealengine.com/5.0/en-US/gameplay-framework-in-unreal-engine/)

### Game Design
- Overwatch GDC Talks
- Game Balance Concepts by Ian Schreiber
- The Art of Game Design by Jesse Schell

### Performance
- [UE5 Performance Guidelines](https://docs.unrealengine.com/5.0/en-US/performance-guidelines-for-unreal-engine/)
- [Scalability Reference](https://docs.unrealengine.com/5.0/en-US/scalability-reference-for-unreal-engine/)

---

## 🎯 Current Sprint Goals

### Week 1 Checklist
- [ ] Project creation and Git setup
- [ ] Basic character movement
- [ ] Camera system
- [ ] Debug HUD
- [ ] Input mapping

### Daily Standup Template
```
Yesterday: [What was completed]
Today: [What will be worked on]
Blockers: [Any impediments]
```

---

Remember: **Ship early, ship often, have fun!** 🎮✨