{
    "targets":[
        {
            "target_name":"ccnpy",
            "sources":[
                "rsc/ccnpy.cc"
            ],
            "conditions":[
                ['OS == "win"',
                {
                    'libraries':["-lnode.lib"]
                }
                ]
            ],
            "cflags!":["-fno-exceptions"],
            "cflags_cc!":["-fno-exceptions"],
            "include_dirs":[
                "<!@(node -p \"process.env['PYTHON_INCLUDE']\")>",
                "<!@(node -p \"require('node-addon-api').include\")"
            ]
        }
    ]
}