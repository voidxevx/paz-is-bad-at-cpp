const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const mod = b.addModule("paz=bad-core", .{
        .optimize = optimize,
        .target = target,
        .link_libc = true,
        .link_libcpp = true,
    });

    const exe = b.addExecutable(.{
        .name = "paz=bad",
        .root_module = mod,
    });

    mod.addCSourceFiles(.{
        .language = .cpp,
        .files = &.{
            // Included source files
            "src/main.cpp",
            "src/boad.cpp",
            "src/playerController.cpp",
        },
        .flags = &.{
            // Compiler flags
            "-std=c++17"
        },
    });

    b.installArtifact(exe);





    const run_step = b.step("run", "Run the app");

    const run_cmd = b.addRunArtifact(exe);
    run_step.dependOn(&run_cmd.step);

    run_cmd.step.dependOn(b.getInstallStep());

    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

}
