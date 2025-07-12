# 🚀 Happily Never After - Quick Setup Guide

## Prerequisites Checklist
- [ ] Unreal Engine 5.3+ installed via Epic Games Launcher
- [ ] Visual Studio 2022 (Windows) or Xcode 14+ (Mac)
- [ ] Git with Git LFS (already done ✅)
- [ ] 50GB+ free disk space

## Step 1: Create Unreal Project (5 mins)

1. **Open Epic Games Launcher**
2. **Launch Unreal Engine 5.3+**
3. **Create New Project:**
   - Games → Next
   - Template: **Third Person**
   - Project Settings:
     - Blueprint/C++: **C++**
     - Target Platform: **Desktop**
     - Quality: **Maximum**
     - Raytracing: **Disabled** (for now)
     - Starter Content: **No Starter Content**
   - Project Location: `/Volumes/T5/`
   - Project Name: `HappilyNeverAfter` (no spaces!)
   - Click **Create**

## Step 2: Integrate with Git (2 mins)

After UE5 creates the project:

```bash
# Navigate to the NEW project folder UE5 created
cd /Volumes/T5/HappilyNeverAfter

# Copy our Git files into the UE5 project
cp -r "/Volumes/T5/Happily Never After/.git" .
cp "/Volumes/T5/Happily Never After/.gitignore" .
cp "/Volumes/T5/Happily Never After/.gitattributes" .
cp "/Volumes/T5/Happily Never After/"*.md .

# Check status
git status

# Add UE5 files
git add .
git commit -m "Add Unreal Engine 5 project files"
git push
```

## Step 3: First Launch Setup (3 mins)

1. **Open the project** (should auto-open after creation)
2. **Let shaders compile** (this takes a few minutes first time)
3. **Configure Editor Preferences:**
   - Edit → Editor Preferences
   - General → Source Code → Source Code Editor: **Visual Studio Code** (if preferred)
   - General → Loading & Saving → Auto Save: **Enabled**

## Step 4: Create Base Classes (10 mins)

In Unreal Editor:

1. **Create C++ Base Character Class:**
   - Tools → New C++ Class
   - Parent: Character
   - Name: `HNACharacterBase`
   - Create Class

2. **Create Game Mode:**
   - Tools → New C++ Class  
   - Parent: GameModeBase
   - Name: `HNAGameMode`
   - Create Class

3. **Wait for Hot Reload** or click "Compile" button

## Step 5: Project Settings (5 mins)

1. **Edit → Project Settings:**
   - Project → Description:
     - Project Name: "Happily Never After"
     - Company Name: Your name/studio
   - Project → Maps & Modes:
     - Default GameMode: `HNAGameMode`
   - Engine → Input:
     - Add Action Mappings:
       - Jump (Space Bar) ✅ Already exists
       - PrimaryFire (Left Mouse Button)
       - SecondaryFire (Right Mouse Button)
       - Ability1 (Q)
       - Ability2 (E)
       - Ultimate (R)

## Step 6: Create Testing Map (5 mins)

1. **File → New Level → Basic**
2. **File → Save Current Level As:**
   - Name: `L_Playground`
   - Save in: Content/Maps/
3. **Add Basic Geometry:**
   - Place Mode → Basic → Cube
   - Scale to create floor (50x50x1)
   - Add some walls and platforms
4. **Set as Default:**
   - Project Settings → Maps & Modes
   - Editor Startup Map: `L_Playground`
   - Game Default Map: `L_Playground`

## Step 7: Quick Movement Test (5 mins)

1. **Open `HNACharacterBase.cpp`**
2. **In the constructor, add:**
```cpp
// Set default movement values
GetCharacterMovement()->JumpZVelocity = 600.0f;
GetCharacterMovement()->AirControl = 0.2f;
GetCharacterMovement()->MaxWalkSpeed = 600.0f;
```

3. **Compile** (Ctrl+Shift+B or Compile button)
4. **Create Blueprint:**
   - Content Browser → C++ → HappilyNeverAfter
   - Right-click `HNACharacterBase`
   - Create Blueprint Class
   - Name: `BP_HeroBase`
   - Save in: Content/Blueprints/Characters/

5. **Test:**
   - Drag `BP_HeroBase` into the level
   - Delete the default ThirdPersonCharacter
   - Play (Alt+P)

## 🎯 Next Immediate Steps

### Today:
1. [ ] Implement basic ability system structure
2. [ ] Create first hero class (Puss-in-Boots)
3. [ ] Add debug HUD

### This Week:
1. [ ] Primary fire implementation
2. [ ] First ability (Boot-Spring Dash)
3. [ ] Basic UI elements
4. [ ] Projectile system

### Commands Cheat Sheet

```bash
# Git
git add .
git commit -m "message"
git push

# Build (if needed)
# Mac
/Engine/Build/BatchFiles/Mac/Build.sh HappilyNeverAfter Mac Development

# In-Editor
Alt+P - Play
Ctrl+Shift+B - Compile
Shift+F1 - Show mouse cursor in play mode
```

## 🔥 Quick Tips

1. **Use Live Coding** (Ctrl+Alt+F11) for faster iteration
2. **Keep the Output Log open** (Window → Developer Tools → Output Log)
3. **Use source control often** - commit after each working feature
4. **Test in Standalone** (Play dropdown → Standalone Game) regularly

## 📚 Helpful Resources

- [UE5 C++ Tutorial](https://docs.unrealengine.com/5.0/en-US/programming-with-cplusplus-in-unreal-engine/)
- [Gameplay Framework](https://docs.unrealengine.com/5.0/en-US/gameplay-framework-in-unreal-engine/)
- Our docs: `DEVELOPMENT_GUIDE.md`, `CLAUDE.md`

---

**You're ready to build!** The fairy tales await their dark reimagining... 🏰⚔️